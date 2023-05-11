#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "pair.h"

#define MAX_N_PAIRS 100

pair_t pairs_in_memory[MAX_N_PAIRS];
unsigned int n_pairs = 0;

static void add_new_pair_in_list(pair_t p) {
    pairs_in_memory[n_pairs] = p;
    n_pairs++;
    pairs_in_memory[n_pairs] = NULL;
}
static bool check_pair_in_memory(pair_t p) {
    bool b = false;
    for(unsigned int i=0; i<n_pairs; i++) {
        if(pairs_in_memory[i] == p) {b = true;}
    }
    return b;
}
static void pop_pair_in_list(pair_t p) {
    bool b = true;
    unsigned int i = 0;
    while(i<n_pairs && b) {
        if(pairs_in_memory[i] == p) {
            for(unsigned int j=i; j<n_pairs; j++) {
                pairs_in_memory[j] = pairs_in_memory[j+1];
            }
            n_pairs--;
            b = false;
        }
        i++;
    }
}


pair_t pair_new(int x, int y) {
    pair_t p;
    p = malloc(sizeof(struct s_pair_t));
    p->fst = x;
    p->snd = y;
    add_new_pair_in_list(p);
    return p;
}

int pair_first(pair_t p) {
    assert(check_pair_in_memory(p));
    return p->fst;
}

int pair_second(pair_t p) {
    assert(check_pair_in_memory(p));
    return p->snd;
}

pair_t pair_swapped(pair_t p) {
    assert(check_pair_in_memory(p));
    pair_t q;
    q = pair_new(p->snd, p->fst);
    return q;
}

pair_t pair_destroy(pair_t p) {
    assert(check_pair_in_memory(p));
    pop_pair_in_list(p);
    free(p);
    return NULL;
}
