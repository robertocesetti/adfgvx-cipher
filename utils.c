//
// Created by Roberto Cesetti  on 20/09/2021.
//

#include <stddef.h>
#include <stdlib.h>
#include "utils.h"

list_st *allocate_node(int value);

list_st *emptylist() {
    return NULL;
}

int isEmpty(list_st *lst) {
    return lst == NULL;
}

list_st *add(list_st *lst, int value) {
    if (lst == NULL) {
        return allocate_node(value);
    }
    list_st *scanner = lst;
    while (scanner->next != NULL) {
        scanner = scanner->next;
    }
    scanner->next = allocate_node(value);
    return lst;
}

int contains(list_st *lst, int value) {
    list_st *scanner = lst;
    while (scanner != NULL) {
        if (scanner->value == value) {
            return 1;
        }
        scanner = scanner->next;
    }
    return 0;
}


list_st *allocate_node(int value) {
    list_st *node = malloc(sizeof(list_st));
    node->value = value;
    return node;
}
