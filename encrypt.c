/*Include*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/*Macros*/
#define MSG_LEN 1000

/*Prototypes*/
int readline(char *, int);
char *encrypt_text(const char *, char *, int);
char *decrypt_text(const char *, char *, int);
void f_encrypt(void);
void f_decrypt(void);

int main(void)
{
    char message[MSG_LEN] = {0}, *encrypt, *decrypt, user_choice;
    int chars_read = 0, key = 0;

    printf("Type (e) to start encrytion, or (d) to start decryption"
    ",or (q) to quit the program.\n--> ");
    scanf(" %c", &user_choice);
    while(getchar() != '\n') ;
    
    switch(user_choice){
        case 'q':   exit(EXIT_SUCCESS);
                    break;
        default :   break;
    }

    if(user_choice == 'e'){
        printf("Enter text for encryption: ");
        chars_read = readline(message, MSG_LEN);
        encrypt = malloc(sizeof(*message) * chars_read + 1);
        if(encrypt == NULL)
            exit(EXIT_FAILURE);
        printf("Enter key to encrypt: ");
        scanf(" %d", &key);

        encrypt = encrypt_text(message, encrypt, key);
        printf("\n%s\n", encrypt);
    }

    /*Decryption*/
    else if(user_choice == 'd'){
    printf("Enter text for decryption: ");
    chars_read = readline(message, MSG_LEN);
    decrypt = malloc(sizeof(*message) * chars_read + 1);
    if(decrypt == NULL)
        exit(EXIT_FAILURE);
    printf("Enter key to decrypt: ");
    scanf(" %d", &key);

    decrypt = decrypt_text(message, decrypt, key);
    printf("\n%s\n", decrypt);
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

char *encrypt_text(const char *source, char *destination, int key)
{
    char *ch = destination;
    while(*source != '\0'){
        if(65 <= *source && *source <= 90){
            *destination = (*source - 65 + key) % 26 + 65;
        }
        else if(97 <= *source && *source <= 122){
            *destination = (*source - 97 + key) % 26 + 97;
        }
        else
            *destination = *source;
        destination++, source++;
    }
    *destination = '\0';
    return ch;
}

char *decrypt_text(const char *source, char *destination, int key)
{
    char *ch = destination;
    while(*source != '\0'){
        if(65 <= *source && *source <= 90){
            if((*source - 65 - key) >= 0)
                *destination = *source - key;
            else
                *destination = 90 + (*source - 65 - key) + 1;
        }
        else if(97 <= *source && *source <= 122){
            if((*source - 97 - key) >= 0)
                *destination = *source - key;
            else
                *destination = 122 + (*source - 97 - key) + 1;
        }
        else
            *destination = *source;
        *destination++, *source++;
    }
    *destination = '\0';
    return ch;
}