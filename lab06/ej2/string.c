#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

struct _s_string {
    char *content;
    unsigned int length;
};

string string_create(const char *word) {
    string str = NULL;
    unsigned int len = 0;
    char c = word[0];
    while(c != '\n'){
        len++;
        c = word[len];
    }
    str = calloc(1, sizeof(struct _s_string));
    str->length =  len;
    str->content = calloc(len, sizeof(char));
    str->content = strncpy(str->content, word, str->length + 1);
    return (str);
}

unsigned int string_length(string str) {
    return (str->length);
}

bool string_less(const string str1, const string str2) {
    bool is_less_eq = true;
    unsigned int len;
    unsigned int len_s1 = str1->length;
    unsigned int len_s2 = str2->length;
    char *s1 = str1->content;
    char *s2 = str2->content;
    bool is_lexeme = true;
    /*
     *lexeme:
     *Part that remains invariable in all the words of the same family; 
     *expresses the meaning common to the whole family and may or may not coincide with a whole word.
    */

    if (len_s1<=len_s2) {len = len_s1;}
    else                {len = len_s2;}

    
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

bool string_eq(const string str1, const string str2) {
    int cmp = strcmp(str1->content, str2->content);
    return (cmp == 0);
}

string string_clone(const string str) {
    return (string_create(str->content));
}

string string_destroy(string str) {
    free(str->content);
    free(str);
    str = NULL;
    return (str);
}

void string_dump(string str, FILE *file) {
    fprintf(file, "%s", str->content);
}

const char *string_ref(string str) {
    return (str->content);
}
