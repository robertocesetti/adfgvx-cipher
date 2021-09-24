//
// Created by Roberto Cesetti on 24/09/2021.
//

#ifndef ROBERTOCESETTI105114_FILEOPERATION_H
#define ROBERTOCESETTI105114_FILEOPERATION_H

#include "list.h"
#include "key.h"
#include <stdio.h>

/**
 * Write to a file.
 *
 * @param data Data to be written to the file.
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

#endif //ROBERTOCESETTI105114_FILEOPERATION_H
