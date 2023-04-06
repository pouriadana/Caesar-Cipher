/*Include*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/*Macros*/
#define MSG_LEN 1000

/*Prototypes*/
int readline(char *, int);

int main(void)
{
    char message[MSG_LEN] = {0};
    char *encrypt;
    int chars_read = 0;

    printf("Enter text for encryption: ");
    chars_read = readline(message, MSG_LEN);
    encrypt = malloc(sizeof(*message) * chars_read);


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
