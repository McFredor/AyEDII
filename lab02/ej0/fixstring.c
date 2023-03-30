#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int length = 0;
    while(s[length]!='\0'){
        length++;
    }
    return length;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool is_eq = true;
    if (fstring_length(s1)!=fstring_length(s2)) {
        is_eq = false;
    }else{
        unsigned int len = fstring_length(s1);
        for(unsigned int i=0; i<len; i++){
            if(s1[i]!=s2[i]){
                is_eq = false;
            }
        }
    }
    return is_eq;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    unsigned int len;
    bool is_less_eq = true;
    if (fstring_length(s1)<=fstring_length(s2)) {
        len = fstring_length(s1);
    }else{
        len = fstring_length(s2);
    }

    for(unsigned int i=0; i<len; i++){
        if(s1[i]>s2[i]){
            is_less_eq = false;
        }
    }
}

