#include "array_helpers.h"

#include <stdio.h>
#include <stdbool.h>

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    
    FILE *fptr;
    fptr = fopen(filepath,"r");
    fscanf(fptr, "%u", &max_size);
    for(unsigned int i=0; i<max_size; i++){
        fscanf(fptr, "%d", &array[i]);
    }
    fclose(fptr);
    return max_size;
}

void array_dump(int a[], unsigned int length) {
    printf("[ %d", a[0]);
    for(unsigned int i=1; i<length; i++) {
        printf(", %d", a[i]);
    }
    printf("]");
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