/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "reverse/array_helpers.h"
#include "stack.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Sort an array given in a file in disk.\n"
           "\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];

    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);
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
