#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "stack.h"
 
typedef struct _s_stack {
    stack_elem elem;
    stack next;
} s_stack;

stack stack_empty() {
    stack s = NULL;
    return s;
}

stack stack_push(stack s, stack_elem e) {
    s_stack *p;
    p = malloc(sizeof(s_stack));
    p->elem = e;
    p->next = s;
    s = p;
    return s;
}

stack stack_pop(stack s) {
    assert(stack_is_empty(s));
    s_stack *p;
    p = s;
    s = s->next;
    free(p);
    return s;
}

unsigned int stack_size(stack s) {
    unsigned int n = 0;
    s_stack *p;
    p = s;
    while(p != NULL){
        n++;
        p = p->next;
    }
    return n;
}


stack_elem stack_top(stack s) {
    assert(!stack_is_empty(s));
    stack_elem e;
    e = s->elem;
    return e;
}

bool stack_is_empty(stack s) {
    bool b = (s == NULL);
    return b;
}

stack_elem *stack_to_array(stack s) {
    unsigned int len = stack_size(s);
    stack_elem *array;
    array = malloc(len * sizeof(stack_elem));
    stack p = s;
    for (unsigned int i=0; i<len; i++) {
        array[i] = p->elem;
        p = p->next; 
    }
    return array;
}

stack stack_destroy(stack s) {
    s_stack *p;
    while(s != NULL){
        p = s->next;
        free(s);
        s = p;
    }
    return s;
}