#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "pqueue.h"

struct s_pqueue
{
    unsigned int size;
    struct s_node *front;
};

struct s_node
{
    pqueue_elem elem;
    float average_grade;
    unsigned int approved_courses;
    float priority;
    struct s_node *next;
};


static float calculate_priority(float average_grade,
                                unsigned int approved_courses)
{
    float priority;
    priority =   0.5 * (average_grade / MAX_GRADE) 
               + 0.5 * (approved_courses / TOTAL_COURSES);
    return priority;
}

static struct s_node *create_node(pqueue_elem e,
                                  float average_grade,
                                  unsigned int approved_courses)
{

    struct s_node *new_node = NULL;
    float priority = calculate_priority(average_grade, approved_courses);
    new_node = malloc(sizeof(struct s_node));
    assert(new_node != NULL);
    new_node->elem = e;
    new_node->average_grade = average_grade;
    new_node->approved_courses = approved_courses;
    new_node->priority = priority;
    new_node->next = NULL;
    return new_node;
}

static struct s_node *destroy_node(struct s_node *node)
{
    assert(node != NULL);
    //Clean memory to residual data for better debugin.  
    node->elem = 0;
    node->average_grade = 0.0;
    node->approved_courses = 0u;
    node->priority = 0.0;
    node->next = NULL;

    free(node);
    node = NULL;
    assert(node == NULL);
    return node;
}

static bool invrep(pqueue q)
{
    return (q != NULL);
}

pqueue pqueue_empty(void)
{
    pqueue q=NULL;
    q = malloc(sizeof(struct s_pqueue));
    q->size = 0u;
    q->front = NULL;
    assert(invrep(q) && pqueue_is_empty(q));
    return q;
}

pqueue pqueue_enqueue(pqueue q,
                      pqueue_elem e,
                      float average_grade,
                      unsigned int approved_courses)
{
    assert(invrep(q));
    struct s_node *new_node = create_node(e, average_grade, approved_courses);
    if (q->front==NULL) {
        q->front = new_node;
    } else {
        struct s_node *better_priority = q->front;
        float node_priority = calculate_priority(average_grade, approved_courses);
        while(     better_priority->priority >= node_priority 
                && better_priority->next != NULL) {
                
            better_priority = better_priority->next;
        }
        better_priority->next = new_node;
    }  
    q->size += 1u;
    assert(invrep(q) && !pqueue_is_empty(q));
    return q;
}

bool pqueue_is_empty(pqueue q)
{
    assert(invrep(q));
    return q->front == NULL;
}


pqueue_elem pqueue_peek(pqueue q)
{
    assert(invrep(q) && !pqueue_is_empty(q));
    return q->front->elem;
}

float pqueue_peek_average_grade(pqueue q)
{
    assert(invrep(q) && !pqueue_is_empty(q));
    return q->front->average_grade;

}

unsigned int pqueue_peek_approved_courses(pqueue q)
{
    assert(invrep(q) && !pqueue_is_empty(q));
    return q->front->approved_courses;
}

float pqueue_peek_priority(pqueue q)
{
    assert(invrep(q) && !pqueue_is_empty(q));
    return q->front->priority;
}

unsigned int pqueue_size(pqueue q)
{
    return q->size;
}

pqueue pqueue_copy(pqueue q)
{
    assert(invrep(q));
    pqueue q_copy = pqueue_empty();
    q_copy->size = q->size;
    q_copy->front = q->front;

    struct s_node *node_from_cp = q->front;
    struct s_node *node_to_cp   = q_copy->front;

    while(node_from_cp->next != NULL) {
        struct s_node *node_to_cp_aux = create_node(node_from_cp->elem,
                                                    node_from_cp->average_grade,
                                                    node_from_cp->approved_courses);    

        node_from_cp = node_from_cp->next;
        node_to_cp->next = node_to_cp_aux;
        node_to_cp = node_to_cp->next;
    }
    return q_copy;
}

pqueue pqueue_dequeue(pqueue q)
{
    assert(invrep(q) && !pqueue_is_empty(q));
    struct s_node * killme=q->front;
    q->front = q->front->next;
    killme = destroy_node(killme);
    q->size -= 1u;
    assert(invrep(q));
    return q;
}

pqueue pqueue_destroy(pqueue q)
{
    assert(invrep(q));
    struct s_node *node = q->front;
    struct s_node *killme;
    while (node != NULL) {
        killme = node;
        node = node->next;
        killme = destroy_node(killme);
    }
    free(q);
    q = NULL;
    assert(q == NULL);
    return q;
}
