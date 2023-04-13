/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100000u;

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

    return result;
}

void cp_reset_and_stats(int copy[], int array[], unsigned int length, int sort_method) {
    /* create a copy of the array */
    array_copy(copy, array, length);

    /* reset counters and set time */
    reset_comparisons_counter();
    reset_swaps_counter();
    set_current_time();

    /* do the actual sorting */
         if (sort_method == 1) {selection_sort(copy, length);}
    else if (sort_method == 2) {insertion_sort(copy, length);}
    else if (sort_method == 3)     {quick_sort(copy, length);}

    /* show statistics for the sort_method */
    printf("statistics for ");
         if (sort_method == 1) {printf("selection_sort\n");}
    else if (sort_method == 2) {printf("insertion_sort\n");}
    else if (sort_method == 3) {printf("quick_sort\n");}
    printf("time elapsed=%g,    comparisons: %10u,    swaps: %10u\n", calculate_elapsed_time(), comparisons_number(), swaps_number());
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];

    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);

    /* create a new array for make a copy of 'the array' */
    int copy[MAX_SIZE];
    
    /*  create a copy of the array,
        reset counters and set time,
        show statistics for the sort_method
        for selection_sort                  */
    cp_reset_and_stats(copy, array, length, 1);

    /* all the same for insertion_sort */
    cp_reset_and_stats(copy, array, length, 2);

    /* all the same for quick_sort */
    cp_reset_and_stats(copy, array, length, 3);



    return EXIT_SUCCESS;
}
