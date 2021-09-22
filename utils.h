//
// Created by Roberto Cesetti on 20/09/2021.
//

#ifndef ROBERTOCESETTI105114_UTILS_H
#define ROBERTOCESETTI105114_UTILS_H

#include "list.h"

typedef struct pair_struct pair_st;

typedef struct key_struct key_st;

/**
 * Data structure used to store pairs of value.
 */
struct pair_struct {

    /**
     * first value
     */
    int s;

    /**
     * Second value
     */
    int k;
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
 * @return the created key struct.
 */
key_st *create_key_struct();

/**
 * Deallocate the key struct from memory.
 *
 * @param key_st the key struct to be deallocated.
 */
void dealloc_key_struct(key_st *key_st);

/**
 * Read the given file.
 *
 * @param file the given file.
 * @return the pointer at the head of the list.
 */
list_st *read_file(char *file);

/**
 * Check that the file has been opened correctly.
 * @param file the open file.
 */
void check_file(const FILE *file);

/************************* TODO.CONTROLLARE.WRITE *************************/
/**
 * Write to a file.
 *
 * @param data data to write to the file
 * @param file_name file to write to
 */
void file_write(list_st *data, const char *file_name);

/************************** TODO.CONTROLLARE.READ *************************/
/**
 * Read an input file
 *
 * @param file the read file.
 * @return the pointer to the head of the list of values saved from the file.
 */
key_st *read_key_file(char *file);

/************************** TODO.CONTROLLARE *************************/
/**
 * Calculate the module.
 *
 * @param val1 first value.
 * @param val2  second value.
 * @return the module between the first and the second value.
 */
int module(int val1, int val2);

/**
 * Calculate the absolute value.
 *
 * @param val
 * @return
 */
int absolute_value(int val);

/************************** TODO.ELIMINARE **************************/


void list_print(list_st *l);

void array_print(byte *array, int size);

void matrix_print(byte **matrix, int size);

#endif //ROBERTOCESETTI105114_UTILS_H
