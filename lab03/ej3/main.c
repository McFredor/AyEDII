#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

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

//static unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size) {
//    
//}

vosort_leters

int main(int argc, char *argv[]) {
    FILE *file;
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    
    /* Parse the filepath given by command line argument. */
    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");

    /* parse the file to fill the arrays and obtain the actual length */
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    for (int res=1; res == 1; length++) {
        res = fscanf(file, "%u", &indexes[length]);
        res = fscanf(file, " -> *%c*\n", &letters[length]);
        if (MAX_SIZE == length) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
    }
    fclose(file);

    sort_leters

    dump(letters, length);

    return EXIT_SUCCESS;
}

