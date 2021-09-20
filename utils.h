//
// Created by Roberto Cesetti  on 20/09/2021.
//

#ifndef ROBERTOCESETTI105114_UTILS_H
#define ROBERTOCESETTI105114_UTILS_H

typedef struct list_struct list_st;


/**
 * Data structure representing a list.
 */
struct list_struct {
    int value;
    list_st *next;
};

/**
 * Creates an empty list.
 * @return an empty list.
 */
list_st *emptylist();

/**
 * Creates a list containing a given number of values.
 * @param nelements number of elements.
 * @return the list.
*/
list_st *createList(int nelements);


/**
 * Checks if the list is empty.
 * @param lst the list.
 * @return 1 if it's empty, 0 otherwise.
 */
int isEmpty(list_st *lst);

/**
 * Adds a value on the list.
 *
 * @param lst the list.
 * @param value the value.
 * @return the list updated.
 */
list_st *add(list_st *lst, int value);

/**
 * Checks if the list contains the given value.
 *
 * @param lst  the list.
 * @param value the value.
 * @return 1 if the list contains the value, 0 otherwise.
 */
int contains(list_st *lst, int value);

//TODO.CHECK
/**
 * Write on a file.
 *
 * @param file the file.
 * @param characters the characters.
void fileWriter(FILE *file, char *characters);
 */


//TODO.ELIMINARE
void list_print(list_st *l);

void arrayPrint(int *array, int size);

void matrixPrint(int **matrix, int size);

#endif //ROBERTOCESETTI105114_UTILS_H
