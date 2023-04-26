#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    y = (x>0) ? x : -x;
}

int main(void) {
    int a=0, res=0;
    a = -10;
    absolute(a, res);
    printf("%d",res);
    return EXIT_SUCCESS;
}

/*
¿Qué valor se muestra por pantalla?
    0

¿Coincide con el programa en el lenguaje del teórico?
    No. En el lenguage teotico la salida es:
    10

    Para que coincida podría hacerce:
↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

int absolute(int x) {
    return ((x>0) ? x : -x);
}

int main(void) {
    int a=0, res=0;
    a = -10;
    res = absolute(a);
    printf("%d",res);
    return EXIT_SUCCESS;
}

*/

