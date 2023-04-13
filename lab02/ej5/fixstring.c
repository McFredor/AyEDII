#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    unsigned int length = 0;
    while(s[length]!='\0' && length!=FIXSTRING_MAX){
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
    bool is_lexeme = true;
    /*
    lexeme:
    Part that remains invariable in all the words of the same family; expresses the meaning common to the whole family and may or may not coincide with a whole word.
    */

    bool is_less_eq = true;
    unsigned int len_s1 = fstring_length(s1);
    unsigned int len_s2 = fstring_length(s2);
    if (len_s1<=len_s2) {
        len = len_s1;
    }else{
        len = len_s2;
    }

    for (unsigned int i=0; i<len; i++) {
        if(is_lexeme){
            if(s1[i]!=s2[i]) {is_lexeme = false;}
        }
        if(s1[i]>s2[i]){
            is_less_eq = false;
            break;
        }else{
            break;
        }
    }
    
    if (len_s2==len && is_lexeme && len_s1!=len_s2) {
        is_less_eq = false;
    }
    return is_less_eq;
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux, s1);
    fstring_set(s1, s2);
    fstring_set(s2, aux);
}


