#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

typedef struct _s_stack s_stack;

stack stack_empty() {
    stack s = NULL;
    return s;
}

stack stack_push(stack s, stack_elem e) {
    stack_elem *arr;
    if(s==NULL) {
        s_stack *p;
        p = malloc(sizeof(s_stack));
        p->elems = malloc(sizeof(stack_elem));
        arr = p->elems;
        arr[0] = e;
        p->size = 1u;
        p->capacity = 1u;
        s = p; 
    }else { 
        if(s->size == s->capacity) {
            s->elems = realloc(s->elems, 2 * s->capacity * sizeof(stack_elem));
            s->capacity = s->capacity * 2;
        }
        arr = s->elems;
        arr[s->size] = e;
        s->size = s->size + 1u;
    }
    return s;
}


stack stack_pop(stack s) {
    assert(!stack_is_empty(s));
    if((s->size -1) == 0) {
        free(s);
        s = NULL;
    }else {
        s->size = s->size - 1u;
    }
    return s;
}

unsigned int stack_size(stack s) {
    unsigned int l;
    l = (s==NULL) ? 0 : s->size;
    return l;
}


stack_elem stack_top(stack s) {
    assert(!stack_is_empty(s));
    stack_elem *arr;
    stack_elem e;
    arr = s->elems;
    e = arr[s->size - 1];
    return e;
}

bool stack_is_empty(stack s) {
    bool b = (s == NULL);
    return b;
}

stack_elem *stack_to_array(stack s) {
    unsigned int len = stack_size(s);
    stack_elem *new_array; 
    if(len!=0){
        new_array = malloc(len * sizeof(stack_elem));
        stack_elem *arr = s->elems;
        for (unsigned int i=0; i<len; i++) {
            new_array[i] = arr[(len - 1) - i];
        }
    }else{new_array = NULL;}
    return new_array;
}

stack stack_destroy(stack s) {
    if(s!=NULL){
        stack_elem *elems = s->elems;
        free(elems);
        free(s);
    s = NULL;  
    }
    
    return s;
}