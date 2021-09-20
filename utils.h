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
 * Create an empty list.
 * @return an empty list.
 */
list_st *emptylist();

/**
 * Check if the list is empty.
 * @param lst the list.
 * @return 1 if it's empty, 0 otherwise.
 */
int isEmpty(list_st *lst);

/**
 * Add a value on the list.
 *
 * @param lst the list.
 * @param value the value.
 * @return the list updated.
 */
list_st *add(list_st *lst, int value);

/**
 * Check if the list contains the given value.
 *
 * @param lst  the list.
 * @param value the value.
 * @return 1 if the list contains the value, 0 otherwise.
 */
int contains(list_st *lst, int value);

#endif //ROBERTOCESETTI105114_UTILS_H
