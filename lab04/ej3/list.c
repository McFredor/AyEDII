#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct _node {
    list_elem elem;
    struct _node *next;
} node;

list empty(void) {
    list l = NULL;
    return l;
}

list addl(list l, list_elem e) {
    node *p;
    p = malloc(sizeof(node));
    p->elem = e;
    p->next = l;
    l = p;
    return l;
}

void destroy(list l) {
    node *p;
    while(l != NULL){
        p = l->next;
        free(l);
        l = p;
    }
}

bool is_empty(list l){
    bool b = (l == NULL);
    return b;
}

list_elem head(list l) {
    assert(!is_empty(l));
    list_elem e;
    e = l->elem;
    return e;
}

void tail(list l) {
    assert(!is_empty(l));
    node *p;
    p = l;
    l = l->next;
    free(p);
}

void addr(list l, list_elem e) {
    node *p, *q;
    q = malloc(sizeof(node));
    q->elem = e;
    q->next = NULL;
    if(!is_empty(l)){
        while(p->next != NULL){
            p = p->next;
        }
        p->next = q;
    }else{
        l = q;
    } 
}

unsigned int length(list l) {
    unsigned int n = 0;
    node *p;
    p = l;
    while(p != NULL){
        n++;
        p = p->next;
    }
    return n;
}

void concat(list l, list l0) {
    node *p;
    if(!is_empty(l)){
        while(p->next != NULL){
            p = p->next;
        }
        p->next = l0;
    }else{
        l = l0;
    } 
}

list_elem index(list l, unsigned int n) {
    assert(length(l) > n);
    node *p;
    list_elem e;
    p = l;
    for(unsigned int i=0; i<n; i++){
        p = p->next;
    }
    e = p->elem;
    return e;
}

void take(list l, unsigned int n) {
    assert(length(l) > n);
    node *p;
    p = l;
    for(unsigned int i=0; i<n; i++){
        p = p->next;
    }
    destroy(p->next);
}

void drop(list l, unsigned int n) {
    assert(length(l) > n);
    node *p;
    for(unsigned int i=0; i<n; i++){
        p = l->next;
        free(l);
        l = p;
    }
}

list copy_list(list l) {
    node *p, *lc, *q;
    if(l != NULL){
        lc = malloc(sizeof(node));
        p = l;
        q = lc;
        while(p->next != NULL){
            q->elem = p->elem;
            q->next = malloc(sizeof(node));
            p = p->next;
            q = q->next;
        }
        q->elem = p->elem;
        q->next = NULL;
    }else{
        lc = NULL;
    }
    return lc;
}
