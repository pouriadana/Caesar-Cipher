#ifndef DECRYPT_F
#define DECRYPT_F
#include <stdio.h>

char *decrypt_text(const char *, char *, int);

char *decrypt_text(const char *source, char *destination, int key)
{
    char *ch = destination;
    while(*source != '\0'){
        if(65 <= *source && *source <= 90){
            *destination = (*source - 65 + 26 - key) % 26 + 65;
        }
        else if(97 <= *source && *source <= 122){
            *destination = (*source - 97 + 26 - key) % 26 + 97;
        }
        else
            *destination = *source;
        *destination++; 
        *source++;
    }
    *destination = '\0';
    return ch;
}
#endif