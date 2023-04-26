#include <stdio.h>

#include "pattern_manager.h"

struct Lexi_atomo {
    char Obj;           // Objeto
    unsigned int Ord;   // Orden
};

static char find(struct Lexi_atomo a[], unsigned int index, unsigned int length, unsigned int alt_index) {
    char letter;
    int b=1;
    for(unsigned int i=0; i<length; i++) {
        if(a[i].Ord == index) {
            b = 0;
            letter = a[i].Obj;
            break;
        }
    }
    if(b){
        for(unsigned int i=0; i<length; i++) {
            if(a[i].Ord >= alt_index) {
                b = 0;
                alt_index++;
                letter = a[i].Obj;
                break;
            }
        }
    }
    return letter;
} 

void Sort_characters(char sorted[], unsigned int indexes[], char letters[], unsigned int length) {
    
    unsigned int alt_index = length;
    struct Lexi_atomo texto[length];
    for(unsigned int i=0; i<length; i++) {
        texto[i].Obj = letters[i];
        texto[i].Ord = indexes[i];
    }

    for(unsigned int i=0; i<length; i++) {
        sorted[i] = find(texto, i, length, alt_index);
    }
}