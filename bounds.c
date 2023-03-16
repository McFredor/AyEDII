#include <stdio.h>
#include <stdbool.h>

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data la_posta;
    la_posta.is_upperbound = true;
    la_posta.is_lowerbound = true;
    la_posta.exists = false;
    la_posta.where = 8888888;

    for (unsigned int i = 0; i < length; i++) {
        if(arr[i] < value) {
            la_posta.is_lowerbound = false;
        }
        else if(arr[i] > value) {
            la_posta.is_upperbound = false;
        }
        else {
            la_posta.exists = true;
            la_posta.where = i;
        }
    }
    return la_posta;
}

int pedirEntero(void) {
    int elValor;
    printf("Sería usted tan amable de proporcionar un número entero a este humilde programa: -> ");
    scanf("%d", &elValor);
    return elValor;
}

void make_table(struct bound_data bd, int value) {
    printf("\n########################################\n");
    printf("#                                      #\n");
    if(bd.is_upperbound || bd.is_lowerbound) {
        printf("#   Cada elemnto del Array es          #\n");
        if(bd.is_upperbound) {
        printf("#   Mayor o igual a %d.                 #\n", value);
        }
        if(bd.is_lowerbound) {
        printf("#   Menor o igual a %d.                 #\n", value);
        }
    }else{
        printf("#   Existen en el Array                #\n");
        printf("#   números menores y mayores.         #\n");
    }
    
    printf("#                                      #\n");
    if(bd.exists) {
    printf("#   %d Está en el Array.                #\n", value);
    printf("#   Exactamente en la posición %d.      #\n", bd.where);

    }else {
    printf("#   %d No está en el Array.             #\n", value);
    }
    printf("#                                      #\n");
    printf("########################################\n\n");
}

int main(void) {
    // Se pide el Arreglo
    printf("¡Hagamos un Arreglo de Enteros!\nPor favor, precise su longitud: -> ");
    int longitud;
    scanf("%d", &longitud);
    int a[longitud];
    printf("Ahora rellenemos los %d valores del Arreglo:\n", longitud);
    int valor;
    for (int i = 0; i < longitud; i++) {
        printf("%d° valor: -> ", i+1);
        scanf("%d", &valor);
        a[i] = valor;
    }

    int value = pedirEntero();
    struct bound_data res = check_bound(value, a, longitud);
    make_table(res, value);
    printf("¡Gracias por ejecutar el programa! ¡Que tenga un buen día!\n\n");
    return 0;
}
