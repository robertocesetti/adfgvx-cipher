//
// Created by Roberto Cesetti on 20/09/2021.
//

#ifndef ROBERTOCESETTI105114_UTILS_H
#define ROBERTOCESETTI105114_UTILS_H

#include "list.h"
#include <stdio.h>

typedef struct pair_struct pair_st;

typedef struct key_struct key_st;

/**
 * Data structure used to store pairs of value.
 */
struct pair_struct {

    /**
     * First value
     */
    int fv;

    /**
     * Second value
     */
    int sv;
};

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
     * Matrix
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

/**
 * Write to a file.
 *
 * @param data Data to write to the file
 * @param file_name File to write to
 */
void file_write(list_st *data, const char *file_name);

/**
 * Read an input file
 *
 * @param file The read file.
 * @param list The list where read values are stored.
 * @param key The structure where the list is stored.
 * @return The pointer to the structure that contains the values saved from the file.
 */
key_st *read_key_file(key_st *key, char *file, list_st *list);

/**
 * Read the given file.
 *
 * @param file The given file.
 * @param list The list where read values are stored.
 * @return The Pointer at the head of the list.
 */
list_st *read_file(char *file, list_st *list);

/**
 * Check that the file has been opened correctly.
 *
 * @param file The open file.
 */
void check_file(const FILE *file);

/**
 * Get the file's size
 *
 * @param file The given file.
 * @return The file's size.
 */
int file_size(FILE *file);

/************************** TODO.CONTROLLARE *************************/
/**
 * Calculate the module.
 *
 * @param val1 First value.
 * @param val2  Second value.
 * @return The module between the first and the second value.
 */
int module(int val1, int val2);

/**
 * Calculate the absolute value.
 *
 * @param value The value.
 * @return The absolute value
 */
int absolute_value(int value);

/************************** TODO.ELIMINARE **************************/


void list_print(list_st *l);

void array_print(byte *array, int size);

void matrix_print(byte **matrix, int size);

#endif //ROBERTOCESETTI105114_UTILS_H
