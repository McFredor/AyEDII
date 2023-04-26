#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    //
    *y = (x>0) ? x : -x;
    //
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    //
    a = -10;
    int *p_res = NULL;
    p_res = &res;
    absolute(a, p_res);
    printf("%d",res);
    //
    return EXIT_SUCCESS;
}

