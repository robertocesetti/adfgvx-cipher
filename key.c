//
// Created by Roberto Cesetti on 20/09/2021.
//

#include <stddef.h>
#include <stdlib.h>
#include "key.h"

key_st *create_key_struct(key_st *k) {
    if (k == NULL) {
        perror("Unable to allocate memory");
    }
    k->c = NULL;
    k->r = NULL;
    k->k = NULL;
    return k;
}

void dealloc_key_struct(key_st *key_st) {
    key_st->c = dealloc_list_struct(key_st->c);
    key_st->r = dealloc_list_struct(key_st->r);
    key_st->k = dealloc_list_struct(key_st->k);
    free(key_st);
}