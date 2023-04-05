#include "array_helpers.h"

#include <stdio.h>
#include <stdbool.h>

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    
    FILE *fptr;
    char caracter;
    fptr = fopen(filepath,"r");
    fscanf(fptr, "%u", &max_size);
    unsigned int i=0;
    while (!feof(fptr)) {
        caracter = getc(fptr);
        if(caracter==' '){i++;}
   }
    if(++i==max_size || 0==max_size){
        i=0;
        rewind(fptr);
        fscanf(fptr, "%u", &max_size);
        while (!feof(fptr) && i<max_size) {
            fscanf(fptr, "%d", &array[i]);
            i++;
        }  
    }else{
        printf("ERROR: Invalid Array!\n");
        max_size = 0;
    }
    fclose(fptr);
    return max_size;
}

void array_dump(int a[], unsigned int length) {
    if(length==0) {
        printf("[]\n");
    }else{
        printf("[%d", a[0]);
        for(unsigned int i=1; i<length; i++) {
            printf(", %d", a[i]);
        }
        printf("]\n");
    }
}

bool array_is_sorted(int a[], unsigned int length) {
    bool is_sorted = true;
    for(unsigned int i=1; i<length; i++) {
        if(a[i-1] > a[i]) {
            is_sorted = false;
        }
    }
    return is_sorted;
}

void array_swap(int a[], unsigned int i, unsigned int j) {
    int aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}
