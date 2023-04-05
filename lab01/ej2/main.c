/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000


unsigned int array_from_stdin(int array[],
                             unsigned int max_size) {
    
    FILE *fptr;
    fptr = stdin;
    fscanf(fptr, "%u", &max_size);
    for(unsigned int i=0; i<max_size; i++){
        fscanf(fptr, "%d", &array[i]);
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


int main() {
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_stdin(array, MAX_SIZE);
     
    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
