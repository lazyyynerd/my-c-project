#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char password[50];
    int hasUpper, hasLower, hasDigit, hasSpecial;
    
   do {
        hasUpper = hasLower = hasDigit = hasSpecial = 0;
        printf("Enter your password: ");
        scanf("%s", password);
        printf("Password entered: %s\n", password);
    
     if(strlen(password) < 8){
        printf("Password must be at least 8 characters long.\n");
        continue;
        } else { for(int i = 0; password[i] != '\0'; i++) {
          if(isupper(password[i])) { hasUpper = 1;}
           if(islower(password[i])) { hasLower = 1;}
           if(isdigit(password[i])) { hasDigit = 1;}
           if(ispunct(password[i])) { hasSpecial = 1;}
        
        }
    } 
    if(!(hasUpper && hasLower && hasDigit && hasSpecial)){
        printf("Password is weak. It must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
    }
       }while(!(hasUpper && hasLower && hasDigit && hasSpecial) || strlen(password) < 8);
    printf("Password is strong.\n");
    
    return 0;
}