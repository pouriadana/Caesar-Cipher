/* A Caesarian encryption/decryption program.    *
*  Written by Pouria Dana                        *
*  pouriadana73@gmail.com                        *
*  April 7, 2023                                 *
*  This code is licensed by the GPL v.3 standard */

/*Include*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "encrypt.h"
#include "decrypt.h"

/*Macros*/
#define MSG_LEN 1000

/*Prototypes*/
int readline(char *, int);

int main(void)
{
    printf("Type (e) to start encrytion, or (d) to start decryption"
    ",or (q) to quit the program.\n");

    for(;;)
    {
        char message[MSG_LEN] = {0}, *encrypt, *decrypt, user_choice;
        int chars_read = 0, key = 0;

        printf("Enter command (e,d,q): \n--> ");    
        scanf(" %c", &user_choice);
        while(getchar() != '\n') ; //Any letter after the first letter is discarded

        switch(tolower(user_choice)){
            case 'q':   exit(EXIT_SUCCESS);
                        break;

            case 'e':   {/*Encryption*/
                        printf("Enter text for encryption: ");
                        chars_read = readline(message, MSG_LEN);
                        encrypt = malloc(sizeof(*message) * chars_read + 1);
                        if(encrypt == NULL)
                            exit(EXIT_FAILURE);
                        printf("Enter key to encrypt (0-25): ");
                        scanf(" %d", &key);

                        encrypt = encrypt_text(message, encrypt, key);
                        printf("\n%s\n", encrypt);
                        break;
            }
            case 'd':   {/*Decryption*/
                        printf("Enter text for decryption: ");
                        chars_read = readline(message, MSG_LEN);
                        decrypt = malloc(sizeof(*message) * chars_read + 1);
                        if(decrypt == NULL)
                            exit(EXIT_FAILURE);
                        printf("Enter key to decrypt: ");
                        scanf(" %d", &key);

                        decrypt = decrypt_text(message, decrypt, key);
                        printf("\n%s\n", decrypt);
                        break;
            }
            default :   printf("Invalid Input... Try again.\n");
                        break;
        }
    }
    return 0;
}

int readline(char *s, int n)
{
    int ch, pos = 0;
    while(isspace(ch = getchar())) ; //NULL STATEMENT
    while(ch != '\n' && ch != EOF){
        if(pos < n)
            s[pos++] = ch;
        ch = getchar();
    }
    s[pos] = '\0';
    return pos;
}