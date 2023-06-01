/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "abb.h" /* TAD abb */

#define POINT 'a' // 'a' or 'b'. 
                  // 'c' is in abb.h                 


void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n",
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

abb abb_from_file(const char *filepath) {
    FILE *file = NULL;
    abb read_tree;

    read_tree = abb_empty();
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0u;
    unsigned int size = 0u;
    int res = 0;
    res = fscanf(file, " %u ", &size);
    if (res != 1) {
        fprintf(stderr, "Invalid format.\n");
        exit(EXIT_FAILURE);
    }
    while (i < size) {
        abb_elem elem;
        res = fscanf(file," %d ", &(elem));
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
        read_tree = abb_add(read_tree, elem);

       ++i;
    }
    fclose(file);
    return read_tree;
}

static void a(abb tree) {
    /*dumping the tree*/
    abb_dump(tree);
    if (!abb_is_empty(tree)) {
        printf("\n");
        printf("raiz: %d\n minimo: %d\n maximo: %d\n", abb_root(tree),
                                                       abb_min(tree),
                                                       abb_max(tree));
    } else {
        printf("\nÁrbol vacío\n");
    }

    /*destroy the tree*/
    tree = abb_destroy(tree);
}

static void b(abb tree) {
    /*
     * Modificado e implementado con un ciclo una interfaz que permita al usuario
     * realizar una de las siguientes operaciones en cada iteración:
     *
     * 1 ........ Mostrar árbol por pantalla
     * 2 ........ Agregar un elemento
     * 3 ........ Eliminar un elemento
     * 4 ........ Chequear existencia de elemento
     * 5 ........ Mostrar longitud del árbol
     * 6 ........ Mostrar raiz, máximo y mínimo del árbol
     * 7 ........ Salir
     *
     * Se debe solicitar un número de entrada para realizar una de las acciones.
     *
     * Para las opciones 2, 3 y 4 se le deberá pedir al usuario que ingrese el
     * elemento a agregar, eliminar o chequear respectivamente.
     *
     * Al salir debe liberarse toda la memoria utilizada.
     *
     */
    bool loop = true;
    int option = 0;
    while(loop) {
        if(option < 1 || option > 7) {
            printf( "\nSe solicitar un número de entrada para realizar una de las acciones:"
                    "\n    1 ........ Mostrar árbol por pantalla"
                    "\n    2 ........ Agregar un elemento"
                    "\n    3 ........ Eliminar un elemento"
                    "\n    4 ........ Chequear existencia de elemento"
                    "\n    5 ........ Mostrar longitud del árbol"
                    "\n    6 ........ Mostrar raiz, máximo y mínimo del árbol"
                    "\n    7 ........ Salir\n");
        }
        printf("\n>>> ");
        scanf("%d", &option);
        if(option == 1) {
            printf("\nMostrar árbol por pantalla...\n");
            abb_dump(tree);
            printf("\n");
        }else
        if(option == 2) {
            printf("\nAgregar un elemento...\n");
            printf("\nSe solicita un número de entrada para agregarlo al arbol: ");
            int number;
            scanf("%d", &number);
            tree = abb_add(tree, number);
            printf("Se agrego %d al árbol.\n", number);
        }else
        if(option == 3) {
            printf("\nEliminar un elemento...\n");
            printf("\nSe solicita un número de entrada para eliminarlo del arbol: ");
            int number;
            scanf("%d", &number);
            tree = abb_remove(tree, number);
            if(abb_exists(tree, number)){printf("Se elimino el %d del árbol.\n", number);}
            else                        {printf("El %d ya no está en el árbol.\n", number);}
        }else
        if(option == 4) {
            printf("\nChequear existencia de elemento...\n");
            printf("\nSe solicita un número de entrada para comprobar si existe en el arbol: ");
            int number;
            scanf("%d", &number);
            if(abb_exists(tree, number)) {
                  printf("El número %d esta en el árbol.\n", number);
            }else{printf("El número %d NO esta en el árbol.\n", number);}
        }else
        if(option == 5) {
            printf("\nMostrar longitud del árbol...\n");
            printf("El árbol contine %u elementos.\n", abb_length(tree));
        }else
        if(option == 6) {
            printf("\nMostrar raiz, máximo y mínimo del árbol...\n");
            if (!abb_is_empty(tree)) {
                printf("\n");
                printf("raiz: %d\n minimo: %d\n maximo: %d\n", abb_root(tree),
                                                               abb_min(tree),
                                                               abb_max(tree));
            } else {printf("\nÁrbol vacío\n");}
        }else
        if(option == 7) {
            printf("\nSalir...\n");
            loop = false;
        }
    }
    tree = abb_destroy(tree);
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* parse the file to obtain an abb with the elements */
    abb tree = abb_from_file(filepath);

    /* select point of the exercise */
    if      (POINT == 'a') {a(tree);}
    else if (POINT == 'b') {b(tree);}

    return (EXIT_SUCCESS);
}
