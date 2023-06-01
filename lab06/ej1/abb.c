#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}

static bool invrep(abb tree) {
    tree = tree;
    // if (tree == NULL) 'tree' is an empty tree.
    // if (tree != NULL) 'tree' is a not-empty tree.
    return true;
}

abb abb_empty(void) {
    abb tree;
    tree = NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    if(!abb_is_empty(tree)) {
        abb_elem root = tree->elem;
        if(elem_less(e, root) || elem_eq(e, root)) {
                tree->left  = abb_add(tree->left , e);}
        else {  tree->right = abb_add(tree->right, e);}
    } else {
        tree = malloc(sizeof(struct _s_abb));
        tree->elem = e;
        tree->left = NULL;
        tree->right= NULL;
    }
    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    bool is_empty = false;
    assert(invrep(tree));
    is_empty = (tree == NULL);
    return is_empty;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists = false;
    assert(invrep(tree));
    if(!abb_is_empty(tree)) {
        abb_elem root = tree->elem;
        if     (elem_eq  (e, root)) {exists = true;}
        else if(elem_less(e, root)) {exists = abb_exists(tree->left , e);}
        else if(elem_less(root, e)) {exists = abb_exists(tree->right, e);}
    }
    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length = 0;
    assert(invrep(tree));
    if(!abb_is_empty(tree)) {
        length = 1u + abb_length(tree->left) + abb_length(tree->right);
    }
    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    if(!abb_is_empty(tree)) {
        abb_elem root = abb_root(tree);
        if(elem_eq(root, e)) {
            abb killme = tree;
            abb hanged_branch;
            abb leaft;
            if(abb_length(killme->left) < abb_length(killme->right)) {
                hanged_branch = killme->left;
                leaft = tree  = killme->right;
                if(leaft != NULL){
                    while(leaft->left != NULL) {leaft = leaft->left;}}
            } else {
                leaft = tree  = killme->left;
                hanged_branch = killme->right;
                if(leaft != NULL){
                    while(leaft->right != NULL) {leaft = leaft->right;}}
            }
            free(killme);
            leaft = hanged_branch;
        } else {
            if     (elem_less(e, root)) {tree->left  = abb_remove(tree->left , e);}
            else if(elem_less(root, e)) {tree->right = abb_remove(tree->right, e);}
        }
    }
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}


abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    root = tree->elem;
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    abb branch = tree->right;
    if(!abb_is_empty(branch))   {max_e = abb_max(branch);}
    else                        {max_e = abb_root(tree);}
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    abb branch = tree->left;
    if(!abb_is_empty(branch))   {min_e = abb_min(branch);}
    else                        {min_e = abb_root(tree);}
    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        #ifndef POINT_C
        abb_dump(tree->left);
        printf("%d ", tree->elem);
        abb_dump(tree->right);
        #endif
        #ifdef POINT_C
        printf("%d ", tree->elem);
        abb_dump(tree->left);
        abb_dump(tree->right);
        #endif
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    if(!abb_is_empty(tree)){
        tree->left  = abb_destroy(tree->left);
        tree->right = abb_destroy(tree->right);
        free(tree);
        tree = NULL;
    }
    assert(tree == NULL);
    return tree;
}

