/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void array_dump(int a[], unsigned int length) {
    fprintf(stdout, "[");
    for (unsigned int i = 0u; i < length; ++i) {
        fprintf(stdout, "%d", a[i]);
        if (i < length - 1) {
            fprintf(stdout, ", ");
        } else {
            fprintf(stdout, "]\n");
        }
    }
}

int main(int argc, char *argv[]) {
   
    unsigned int length = 5;
    int array[5] = {0, 1, 2, 3, 4};
    printf("Original: ");
    array_dump(array, length);

    int *new_array=NULL;
    
    stack overflow = stack_empty();
    // push an pop one element in overflow
    overflow = stack_push(overflow, 79);
    overflow = stack_pop(overflow);
    printf("\nWork Well for stack_pop with length 1.\n");
    //Now overflow is empty. I try to push a new element.
    overflow = stack_push(overflow, 42);
    printf("Work Well. I can insert new elements. Eg: %d is one.\n", stack_top(overflow));
    overflow = stack_pop(overflow);
    //stack_to_array return null for a empty stack?
    printf("stack_to_array ");
    if(stack_to_array(overflow)==NULL){printf("is NULL");}else{printf("isn't NULL");}
    printf(" for an empty stack\n");
    //stack_to_array return elements in the rigth order?
    for(unsigned int i=0; i<length; i++) {
        overflow = stack_push(overflow, array[i]);
    }
    new_array = stack_to_array(overflow);
    overflow = stack_destroy(overflow);



    printf("Reversed: ");
    array_dump(new_array, length);
    return (EXIT_SUCCESS);
}
