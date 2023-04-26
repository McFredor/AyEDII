/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    //implement based in the player rank
    bool is_before = true;
    if(x.rank > y.rank) {is_before = false;}
    return is_before;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

static void swap(player_t a[], unsigned int i, unsigned int j) {
    player_t aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}
static void insert(player_t a[], unsigned int i) {
    unsigned int j = i;
    while (j >= 1u && goes_before(a[j], a[j-1])) {
        swap(a,j-1, j);
        j = j-1;
    }
}
static void insertion_sort(player_t a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
}

void sort(player_t a[], unsigned int length) {
    // implement with insertion sort
    insertion_sort(a, length);
}