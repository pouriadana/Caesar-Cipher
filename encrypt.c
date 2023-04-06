/*Include*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/*Macros*/
#define MSG_LEN 1000

/*Prototypes*/
int readline(char *, int);
char *encrypt_text(const char *, char *, int);

int main(void)
{
    char message[MSG_LEN] = {0};
    char *encrypt;
    int chars_read = 0, key = 0;

    printf("Enter text for encryption: ");
    chars_read = readline(message, MSG_LEN);
    encrypt = malloc(sizeof(*message) * chars_read + 1);
    if(encrypt == NULL)
        exit(EXIT_FAILURE);
    printf("Enter key to encrypt: ");
    scanf(" %d", &key);

    encrypt = encrypt_text(message, encrypt, key);
    printf("\n%s", encrypt);

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
    int wrapped = 0;
    while(*source != '\0'){
        if(65 <= *source && *source <= 90){
            if(*source - 65 + key > 25)
                *destination = ((*source - 65 + key) % 25) + 65 - 1;
            else
                *destination = ((*source - 65 + key) % 25) + 65;
        }
        else if(97 <= *source && *source <= 122){
            if(*source - 97 + key > 25)
                *destination = ((*source - 97 + key) % 25) + 97 - 1;
            else
                *destination = ((*source - 97 + key) % 25) + 97;
        }
        else
            *destination = *source;
        destination++, source++;
    }
    *destination = '\0';
    return ch;
}