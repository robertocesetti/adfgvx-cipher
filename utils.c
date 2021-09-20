//
// Created by Roberto Cesetti  on 20/09/2021.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

list_st *allocate_node(int value);

list_st *emptylist() {
    return NULL;
}

list_st *createList(int nElements) {
    int i = --nElements;
    list_st *el1;
    list_st *el2 = emptylist();
    while (i >= 0) {
        el1 = malloc(sizeof(list_st));
        el1->value = i;
        el1->next = el2;
        el2 = el1;
        i--;
    }
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

//TODO.ELIMINARE

void list_print(list_st *l) {
    while (l != NULL) {
        printf("%d\n", l->value);
        l = l->next;
    }
}

void arrayPrint(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%3d ", array[i]);
    }
    printf("\n\n");

}

void matrixPrint(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}