#include <stdlib.h>

#include "strfuncs.h"

size_t string_length(const char *str) {
    size_t s;
    unsigned int i=0;
    while(str[i] != '\0') {i++;}
    s = i * sizeof(char);
    return s;
}   

char *string_filter(const char *str, char c) {
    char *str_f;
    unsigned int i=1u;
    for(unsigned int j=0; str[j] != '\0'; j++) {
        if(str[j] != c) {i++;}
    }
    str_f = malloc(i * sizeof(char));
    i=0;
    for(unsigned int j=0; str[j] != '\0'; j++) {
        if(str[j] != c) {
            str_f[i] = str[j];
            i++;
        }
    }
    str_f[i] = '\0';
    return str_f;
}
