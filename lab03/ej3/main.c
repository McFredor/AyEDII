#include <stdlib.h>
#include <stdio.h>

#include "pattern_manager.h"

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

static void print_help(char *program_name) {
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

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_sixe) {
    /* Parse the filepath given by command line argument. */
    unsigned int len=0; 
    FILE *file=NULL;
    file = fopen(path, "r");

    /* parse the file to fill the arrays and obtain the actual length */
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    for (int res=1; res == 1 && !feof(file); len++) {
        res = fscanf(file, "%u", &indexes[len]);
        res = fscanf(file, " -> *%c*\n", &letters[len]);
        if (max_sixe == len) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
    }
    fclose(file);
    return len;
}


int main(int argc, char *argv[]) {
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    
    for(unsigned int i=0; i<MAX_SIZE; i++) {
        indexes[i]=0;
        letters[i]='\0';
        sorted[i]='\0';
    }

    /* Parse the filepath given by command line argument. */
    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }
    length = data_from_file(argv[1], indexes, letters, MAX_SIZE);
    Sort_characters(sorted, indexes, letters, length);

    dump(sorted, length);

    return EXIT_SUCCESS;
}

