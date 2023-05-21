#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *string_clone(const char *str, size_t length) {
/*
*   The before code stores the data on the stack instead of on the heap.
*   What produces that data is lost once the function is finished.  
*/
    char *clone = NULL;
    clone = malloc((length * sizeof(char))+1);
    for (size_t i=0; i<length; i++) {
        clone[i] = str[i];
    }
    clone[length] = '\0';
    return clone;
}


int main(void) {
    char *original=""; //  The type is the same. Then I assumed to change its content.
    char *copy=NULL;

    /*
    *   copy = string_clone(original, sizeof(original)/sizeof(char) - 1);
    *   It isn't the correct way to work with strings.
    */
    copy = string_clone(original, strlen(original));

    
    printf("Original: %s\n", original); 
    
    //  I can only modify variables if they already exist.
    //  An if was added.
    if(strlen(copy)>=5){
        copy[0] = 'A';
        copy[1] = ' ';
        copy[2] = 'l';
        copy[3] = 'o';
        copy[4] = 'n';
        copy[5] = 'g'; 
    }
    printf("Copia   : %s\n", copy);

    // A necessary free was added.
    free(copy);
    copy=NULL;

    return EXIT_SUCCESS;
}

