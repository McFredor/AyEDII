#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c;
    c = malloc(sizeof(struct _counter));
    c->count = 0u;
    return c;
}

void counter_inc(counter c) {
    c->count = c->count + 1;
}

bool counter_is_init(counter c) {
    bool b;
    b = (c->count == 0u);
    return b;
}

void counter_dec(counter c) {
    c->count = c->count - 1;
}

counter counter_copy(counter c) {
    counter d;
    d = counter_init();
    d->count = c->count;
    return d;
}

void counter_destroy(counter c) {
    c->count = 0u;
    free(c);
}
