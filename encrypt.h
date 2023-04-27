#ifndef ENCRYPT_F
#define ENCRYPT_F
#include <stdio.h>

#define ALPHABET_LEN 26

char *encrypt_text(const char *, char *, int);

char *encrypt_text(const char *source, char *destination, int key)
{
    char *ch = destination;
    while(*source != '\0'){
        if('A' <= *source && *source <= 'Z'){
            *destination = (*source - 'A' + key) % ALPHABET_LEN + 'A';
        }
        else if('a' <= *source && *source <= 'z'){
            *destination = (*source - 'a' + key) % ALPHABET_LEN + 'a';
        }
        else
            *destination = *source;
        destination++, source++;
    }
    *destination = '\0';
    return ch;
}
#endif