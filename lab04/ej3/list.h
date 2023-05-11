#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <stdbool.h>


typedef int list_elem;
typedef struct _node * list;

/* Constructors */
list empty(void);
/*
    Create a new list with initial value. Allocates new memory.
*/

void addl(list *l, list_elem e);
/*
    Add the element e in the begin of the list.
*/

/* Destroy */
void destroy(list l);
/*
   Frees memory for c.
*/

/* Operations */
bool is_empty(list l);
/*
    Return whether the list l is empty.
*/

list_elem head(list l);
/*
    Return the first element of the list.
    PRECONDITION: !is_empty(l)
*/

void tail(list l);
/*
    DELETE the first element of the list.
    PRECONDITION: !is_empty(l)
*/

void addr(list l, list_elem e);
/*
    Add the element e in the end of the list.
*/

unsigned int length(list l);
/*
    Return the number of elements in the list.
*/

void concat(list l, list l0);
/*
    Add at the end of l all the elements of l0 in the same order.
*/

list_elem index(list l, unsigned int n);
/*
    Return the n-th element in the list.
    PRECONDITION: length(l) > n
*/

void take(list l, unsigned int n);
/*
    Leaves only the first n elements in l, deletining the rest.
    PRECONDITION: length(l) > n
*/

void drop(list l, unsigned int n);
/*
    Delete the first n elements in l.
    PRECONDITION: length(l) > n
*/

list copy_list(list l);
/*
    Makes a copy of list l. Allocates new memory.
*/

#endif
