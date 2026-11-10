/*
 * ============================================================================
 * Game Title: Stickman Runner Mini-Game
 * Language  : C (ANSI C / C99 standard)
 * OS        : Cross-platform (Windows & POSIX Linux/macOS)
 * Description: An ASCII endless runner mini-game featuring jump, duck,
 *              dynamic obstacles, score system, and item collection.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#if defined(_WIN32) || defined(_WIN64)
    #include <conio.h>
    #include <windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
    #define CLEAR_SCREEN() system("cls")
#else
    #include <unistd.h>
    #include <termios.h>
    #include <fcntl.h>
    #define SLEEP_MS(ms) usleep((ms) * 1000)
    #define CLEAR_SCREEN() printf("\033[H\033[J")

    /* Non-blocking keyboard check for Linux/macOS */
    int _kbhit(void) {
        struct termios oldt, newt;
        int ch, oldf;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);
        if (ch != EOF) {
            ungetc(ch, stdin);
            return 1;
        }
        return 0;
    }
    int _getch(void) {
        return getchar();
    }
#endif

/* Game Parameters */
#define SCREEN_WIDTH  50
#define SCREEN_HEIGHT 10
#define GROUND_LEVEL  7

/* Global Game States */
typedef enum { STATE_RUN, STATE_JUMP, STATE_DUCK } PlayerState;

typedef struct {
    int x, y;
    PlayerState state;
    int jumpTimer;
} Stickman;

typedef struct {
    int x, y;
    int type; // 0: Ground Crate, 1: High Flying Bird, 2: Bonus Star
    int active;
} Entity;

/* Global Variables */
Stickman player;
Entity obstacle;
int score = 0;
int gameOver = 0;
int animFrame = 0;

/* Initialize Game State */
void initGame() {
    player.x = 5;
    player.y = GROUND_LEVEL;
    player.state = STATE_RUN;
    player.jumpTimer = 0;
    
    obstacle.x = SCREEN_WIDTH - 2;
    obstacle.y = GROUND_LEVEL;
    obstacle.type = rand() % 3;
    obstacle.active = 1;
    
    score = 0;
    gameOver = 0;
}

/* Handle Keyboard Inputs */
void processInput() {
    if (_kbhit()) {
        char key = _getch();
        if ((key == ' ' || key == 'w' || key == 'W') && player.state == STATE_RUN) {
            player.state = STATE_JUMP;
            player.jumpTimer = 5; // Duration in mid-air
        } else if ((key == 's' || key == 'S') && player.state == STATE_RUN) {
            player.state = STATE_DUCK;
        } else if (key == 'q' || key == 'Q') {
            gameOver = 1;
        }
    }
}

/* Update Game Physics & Logic */
void updateGame() {
    // 1. Handle Stickman Jump/Duck Physics
    if (player.state == STATE_JUMP) {
        player.y = GROUND_LEVEL - 3; // Elevated position
        player.jumpTimer--;
        if (player.jumpTimer <= 0) {
            player.state = STATE_RUN;
            player.y = GROUND_LEVEL;
        }
    } else if (player.state == STATE_DUCK) {
        player.y = GROUND_LEVEL;
        // Duck state resets back after 1 tick if key not held
    }

    // 2. Move Obstacles & Collectibles
    obstacle.x--;
    if (obstacle.x < 2) {
        obstacle.x = SCREEN_WIDTH - 3;
        obstacle.type = rand() % 3; // 0=Ground Crate, 1=High Bird, 2=Star
        obstacle.y = (obstacle.type == 1) ? GROUND_LEVEL - 2 : GROUND_LEVEL;
        score += 10; // Reward for passing obstacle
    }

    // 3. Collision Detection
    if (obstacle.x >= player.x - 1 && obstacle.x <= player.x + 1) {
        if (obstacle.type == 0 && player.y >= GROUND_LEVEL) {
            // Hit Crate!
            gameOver = 1;
        } else if (obstacle.type == 1 && player.state != STATE_DUCK && player.y == GROUND_LEVEL) {
            // Hit High Bird (Didn't duck)!
            gameOver = 1;
        } else if (obstacle.type == 2) {
            // Collected Star!
            score += 50;
            obstacle.x = SCREEN_WIDTH - 3; // Reset star
            obstacle.type = rand() % 2;
        }
    }

    // Reset duck state for next cycle
    if (player.state == STATE_DUCK) {
        player.state = STATE_RUN;
    }

    animFrame = (animFrame + 1) % 2;
}

/* Render Frame to Terminal */
void renderGame() {
    CLEAR_SCREEN();

    printf("==================================================\n");
    printf("   C STICKMAN RUNNER | Score: %05d | Q: Quit\n", score);
    printf("==================================================\n\n");

    for (int r = 0; r < SCREEN_HEIGHT; r++) {
        for (int c = 0; c < SCREEN_WIDTH; c++) {
            // Render Border
            if (c == 0 || c == SCREEN_WIDTH - 1) {
                printf("|");
                continue;
            }

            // Render Ground
            if (r == GROUND_LEVEL + 1) {
                printf("=");
                continue;
            } else if (r > GROUND_LEVEL + 1) {
                printf(" ");
                continue;
            }

            // Render Stickman Character
            if (c == player.x) {
                if (player.state == STATE_JUMP) {
                    if (r == player.y - 1) { printf(" O "); c++; continue; }
                    if (r == player.y)     { printf("/|\\"); c += 2; continue; }
                    if (r == player.y + 1) { printf("/ \\"); c += 2; continue; }
                } else if (player.state == STATE_DUCK) {
                    if (r == GROUND_LEVEL)     { printf(" o>"); c += 2; continue; }
                } else { // Normal Running Animation
                    if (r == GROUND_LEVEL - 2) { printf(" O "); c++; continue; }
                    if (r == GROUND_LEVEL - 1) { printf("/|\\"); c += 2; continue; }
                    if (r == GROUND_LEVEL)     { 
                        printf(animFrame == 0 ? "/ \\" : " | "); 
                        c += (animFrame == 0 ? 2 : 2); 
                        continue; 
                    }
                }
            }

            // Render Obstacles / Items
            if (c == obstacle.x) {
                if (obstacle.type == 0 && r == GROUND_LEVEL) {
                    printf("[#]"); c += 2; continue; // Crate
                } else if (obstacle.type == 1 && r == GROUND_LEVEL - 2) {
                    printf("<o>"); c += 2; continue; // Flying Bird
                } else if (obstacle.type == 2 && r == GROUND_LEVEL - 1) {
                    printf(" * "); c += 2; continue; // Star Bonus
                }
            }

            printf(" ");
        }
        printf("\n");
    }

    printf("==================================================\n");
    printf(" Controls: [SPACE/W] Jump | [S] Duck | [Q] Quit\n");
}

/* Main Function */
int main() {
    srand((unsigned int)time(NULL));
    initGame();

    printf("Press ENTER to start playing Stickman Runner...");
    getchar();

    while (!gameOver) {
        processInput();
        updateGame();
        renderGame();
        SLEEP_MS(100); // Main game loop speed
    }

    printf("\nGAME OVER! Final Score: %d\n", score);
    return 0;
}