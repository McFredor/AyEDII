#include <stdio.h>
#include <stdlib.h>

#include "string.h"

#define N_WORDS 4

int main(void) {
    string words[N_WORDS];
    words[0] = string_create("hola");
    words[1] = string_create("mundo"); 
    words[2] = string_create("auto"); 
    words[3] = string_create("automovil"); 

    printf("\n"
           "Probando string_eq() y string_less()\n"
           "-------------------------------------\n\n");

    for (int i=0; i < N_WORDS; i++) {
        for (int j=0; j < N_WORDS; j++) {
            if (string_eq(words[i], words[j])) {
                printf("Los strings '%s' y '%s' son iguales\n", string_ref(words[i]), string_ref(words[j]));
            }else{
            printf("El string '%s' va %s alfabeticamente que '%s'\n\n",
                                                                        string_ref(words[i]),
                                                                        string_less(words[i], words[j]) ? "antes": "despues",
                                                                        string_ref(words[j]));
            }
        }
    }
    return EXIT_SUCCESS;
}

