#ifndef DECRYPT_F
#define DECRYPT_F
#include <stdio.h>

char *decrypt_text(const char *, char *, int);

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
#endif