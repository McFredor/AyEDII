#include <stdlib.h>
#include <assert.h>
#include "dict.h"
#include "key_value.h"

struct _node_t {
    dict_t left;
    dict_t right;
    key_t key;
    value_t value;
};

static bool dict_is_empty(dict_t dict){
    bool b = false;
    if(dict != NULL){b = true;}
    return b;
}

static bool invrep(dict_t d) {
    bool b = true;
    if(d != NULL){
        if(d->left != NULL){
            if(d->left->key > d->key){
                b = false;
            }
        }
        if(d->right != NULL){
            if(d->right->key <= d->key){
                b = false;
            }
        }
    }
    return b;
    return true;
}

dict_t dict_empty(void) {
    dict_t dict = NULL;
    assert(invrep(dict));
    return dict;
}

dict_t dict_add(dict_t dict, key_t word, value_t def) {
    assert(invrep(dict));
    if(!dict_is_empty(dict)) {
        key_t root = dict->key;
        if(key_less(word, root)) {
                dict->left  = dict_add(dict->left , word, def);}
        else {  dict->right = dict_add(dict->right, word, def);}
    } else {
        dict = malloc(sizeof(dict_t));
        dict->left = NULL;
        dict->right= NULL;
        dict->key = word;
        dict->value = def;
    }
    assert(invrep(dict) && dict_exists(dict, word));
    return dict;
}

value_t dict_search(dict_t dict, key_t word) {
    key_t def=NULL;
    if(dict_exists(dict, word)){
        dict_t d = dict;
        bool b = true;
        while(b){
            if(key_less(word, d->key)) {
                    d = d->left;
            }else{  d = d->right;}
        
            if(key_eq(d->key, word)){
                    b = false;
            }        
        }
        def = d->value;
    }
    return def;
}

bool dict_exists(dict_t dict, key_t word) {
    bool exists = false;
    assert(invrep(dict));
    if(!dict_is_empty(dict)) {
        key_t root = dict->key;
        if     (key_eq  (word, root)) {exists = true;}
        else if(key_less(word, root)) {exists = dict_exists(dict->left , word);}
        else if(key_less(root, word)) {exists = dict_exists(dict->right, word);}
    }
    return exists;
}

unsigned int dict_length(dict_t dict) {
    unsigned int length = 0;
    assert(invrep(dict));
    if(!dict_is_empty(dict)) {
        length = 1u + dict_length(dict->left) + dict_length(dict->right);
    }
    assert(invrep(dict));
    return length;
}

dict_t dict_remove(dict_t dict, key_t word) {
    assert(invrep(dict));
    if(!dict_is_empty(dict)) {
        key_t root = dict->key;
        if(key_eq(root, word)) {
            dict_t killme = dict;
            dict_t hanged_branch;
            dict_t leaft;
            if(dict_length(killme->left) < dict_length(killme->right)) {
                hanged_branch = killme->left;
                leaft = dict  = killme->right;
                if(leaft != NULL){
                    while(leaft->left != NULL) {leaft = leaft->left;}}
            } else {
                leaft = dict  = killme->left;
                hanged_branch = killme->right;
                if(leaft != NULL){
                    while(leaft->right != NULL) {leaft = leaft->right;}}
            }
            free(killme);
            leaft = hanged_branch;
        } else {
            if     (key_less(word, root)) {dict->left  = dict_remove(dict->left , word);}
            else if(key_less(root, word)) {dict->right = dict_remove(dict->right, word);}
        }
    }
    assert(invrep(dict) && !dict_exists(dict, word));
    return dict;
}

dict_t dict_remove_all(dict_t dict) {
    assert(invrep(dict));
    if(!dict_is_empty(dict)){
        dict->left  = dict_remove_all(dict->left);
        dict->right = dict_remove_all(dict->right);
        free(dict);
        dict = NULL;
    }
    assert(dict == NULL);
    return dict;
}

void dict_dump(dict_t dict, FILE *file) {
    assert(invrep(dict));
    if (dict != NULL) {
        dict_dump(dict->left, file);
        fprintf(file, "\n");
        key_dump(dict->key, file);
        fprintf(file, ":\n   ");
        key_dump(dict->value, file);
        fprintf(file, "\n");
        dict_dump(dict->right, file);
    }
}

dict_t dict_destroy(dict_t dict) {
    dict_remove_all(dict);
    return dict;
}

