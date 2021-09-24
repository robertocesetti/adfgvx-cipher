//
// Created by Roberto Cesetti on 20/09/2021.
//

#ifndef ROBERTOCESETTI105114_KEY_H
#define ROBERTOCESETTI105114_KEY_H

#include "list.h"
#include <stdio.h>

typedef struct key_struct key_st;

/**
 * Data structure used to store the key.
 */
struct key_struct {
    /**
     * Column
     */
    list_st *c;

    /**
     * Row
     */
    list_st *r;

    /**
     * Key
     */
    list_st *k;
};

/**
 * Create a key struct.
 *
 * @param k The key structure to be created.
 * @return The created key struct.
 */
key_st *create_key_struct(key_st *k);

/**
 * Deallocate the key struct from memory.
 *
 * @param key_st The key struct to be deallocated.
 */
void dealloc_key_struct(key_st *key_st);

#endif //ROBERTOCESETTI105114_KEY_H
