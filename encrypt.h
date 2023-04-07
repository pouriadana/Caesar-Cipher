#ifndef ENCRYPT_F
#define ENCRYPT_F
#include <stdio.h>

char *encrypt_text(const char *, char *, int);

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
#endif