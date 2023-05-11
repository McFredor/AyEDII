#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "counter.h"

struct _counter {
    unsigned int count;
    unsigned int check;
};

counter counter_init(void) {
    counter c;
    c = malloc(sizeof(struct _counter));
    c->count = 0u;
    c->check = 0u;
    return c;
}

void counter_inc(counter c) {
    assert(c->count == c->check);
    c->count = c->count + 1;
    c->check = c->check + 1;  
}

bool counter_is_init(counter c) {
    assert(c->count == c->check);
    bool b;
    b = (c->count == 0u);
    return b;
}

void counter_dec(counter c) {
    assert(c->count == c->check);
    c->count = c->count - 1;
    c->check = c->check - 1;  
}

counter counter_copy(counter c) {
    assert(c->count == c->check);
    counter d;
    d = counter_init();
    d->count = c->count;
    d->check = c->check; 
    return d;
}

void counter_destroy(counter c) {
    assert(c->count == c->check);
    c->count = 0u;
    c->check = 1u;
    free(c);
}
