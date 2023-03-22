#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;
    res.where = 8888888;

    for (unsigned int i = 0; i < length; i++) {
        if(arr[i] < value) {
            res.is_lowerbound = false;
        }
        else if(arr[i] > value) {
            res.is_upperbound = false;
        }
        else {
            res.exists = true;
            res.where = i;
        }
    }
    return res;
}

int getInt(void) {
    int elValor;
    printf("Sería usted tan amable de proporcionar un número entero a este humilde programa: -> ");
    scanf("%d", &elValor);
    return elValor;
}

void show_bound(struct bound_data bd, int value) {
    if(!(bd.is_upperbound || bd.is_lowerbound)) {
        printf("Ok. El número %d es uno cualquiera del arreglo. ", value);
        printf("Existen por lo menos un valor mayor y otro menor a el.\n");
    }else if(bd.exists) {
        if(bd.is_upperbound) {
        printf("máximo\n");
        }
        if(bd.is_lowerbound) {
        printf("mínimo\n");
        }
        printf("%d\n", bd.where);
    }else{
        if(bd.is_upperbound) {
        printf("cota superior\n");
        }
        if(bd.is_lowerbound) {
        printf("cota inferior\n");
        }
    }
}

void make_table(struct bound_data bd, int value) {
    printf("\n########################################\n");
    printf("#                                      #\n");
    printf("#   Ok. El número %d es                 #\n", value);
    if(!(bd.is_upperbound || bd.is_lowerbound)) {
        printf("#   uno cualquiera del arreglo.        #\n");
        printf("#   Existen por lo menos un valor      #\n");
        printf("#   mayor y otro menor a el.           #\n");
    }else if(bd.exists) {
        if(bd.is_upperbound) {
        printf("#   el máximo del arreglo.             #\n");
        }
        if(bd.is_lowerbound) {
        printf("#   el mínimo del arreglo.             #\n");
        }
        printf("#                                      #\n");
        printf("#   Y se encuentra exactamente         #\n");
        printf("#   en la posición %d.                  #\n", bd.where);
    }else{
        if(bd.is_upperbound) {
        printf("#   cota superior del arreglo.         #\n");
        }
        if(bd.is_lowerbound) {
        printf("#   cota inferior del arreglo.         #\n");
        }
    }
    printf("#                                      #\n");
    printf("########################################\n\n");
    printf("¡Gracias por ejecutar el programa! ¡Que tenga un buen día!\n\n");
}



int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;
    // Se pide el Arreglo
    printf("Ahora rellenemos los %d valores del Arreglo:\n", ARRAY_SIZE);
    int i_value;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d° valor: -> ", i+1);
        scanf("%d", &i_value);
        a[i] = i_value;
    }

    value = getInt();
    //
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    show_bound(result, value);
    // For a more human-friendly output is recommended replace the previous function with:
    //make_table(result, value);

    return EXIT_SUCCESS;
}

