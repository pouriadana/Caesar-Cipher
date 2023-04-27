#ifndef DECRYPT_F
#define DECRYPT_F
#include <stdio.h>

#define ALPHABET_LEN 26

char *decrypt_text(const char *, char *, int);

char *decrypt_text(const char *source, char *destination, int key)
{
    char *ch = destination;
    while(*source != '\0'){
        if('A' <= *source && *source <= 'Z'){
            *destination = (*source - 'A' + ALPHABET_LEN - key) % ALPHABET_LEN + 'A';
        }
        else if('a' <= *source && *source <= 'z'){
            *destination = (*source - 'a' + ALPHABET_LEN - key) % ALPHABET_LEN + 'a';
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