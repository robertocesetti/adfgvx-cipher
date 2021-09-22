//
// Created by Roberto Cesetti  on 20/09/2021.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

list_st *allocate_node(byte value);

list_st *empty_list() {
    return NULL;
}

list_st *create_list(int nElements) {
    int i = --nElements;
    list_st *el1;
    list_st *el2 = empty_list();
    while (i >= 0) {
        el1 = malloc(sizeof(list_st));
        el1->value = i;
        el1->next = el2;
        el2 = el1;
        i--;
    }
}

int is_empty(list_st *lst) {
    return lst == NULL;
}

int sizeof_list(list_st *list) {
    list_st *scanner = list;
    int list_size = 0;
    if (scanner != NULL) {
        list_size = 1;
        while (scanner->next != NULL) {
            list_size++;
            scanner = scanner->next;
        }
    }
    return list_size;
}

list_st *add(list_st *lst, byte value) {
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

list_st *remove_value(list_st *lst, int index) {
    list_st *scanner = lst;
    if (index == 0) {
        return remove_head(lst);
    }
    while ((index) != 1) {
        scanner = scanner->next;
        index--;
    }
    list_st *temp = scanner->next->next;
    free(scanner->next);
    scanner->next = temp;
    return lst;
}

list_st *remove_head(list_st *lst) {
    list_st *temp = lst->next;
    free(lst);
    return temp;
}

list_st *concat_list(list_st *first_list, list_st *second_list) {
    if (first_list == NULL && second_list == NULL) {
        return NULL;
    } else {
        while (second_list != NULL) {
            add(first_list, second_list->value);
            second_list = second_list->next;
        }
        return first_list;
    }
}

byte get(list_st *lst, int index) {
    list_st *scanner = lst;
    while (index != 0) {
        scanner = scanner->next;
        index--;
    }
    return scanner->value;
}

int contains(list_st *lst, byte value) {
    list_st *scanner = lst;
    while (scanner != NULL) {
        if (scanner->value == value) {
            return 1;
        }
        scanner = scanner->next;
    }
    return 0;
}

list_st *allocate_node(byte value) {
    list_st *node = malloc(sizeof(list_st));
    node->value = value;
    node->next = NULL;
    return node;
}

void file_write(list_st *data, const char *file_name) {
    FILE *written_file = fopen(file_name, "wb");
    if (written_file == NULL) {
        /* File not created */
        perror("Unable to create file.\n");
        exit(-1);
    }
    while (data != NULL) {
        fputc(data->value, written_file);
        data = data->next;
    }
    fclose(written_file);
}

//TODO.CHECK

int module(int val1, int val2) {
    int result = val1 % val2;

}

int absolute_value(int val) {

}

//TODO.ELIMINARE

void list_print(list_st *l) {
    while (l != NULL) {
        printf("%d ", l->value);
        l = l->next;
    }
    printf("\n");
}

void array_print(byte *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%3d ", array[i]);
    }
    printf("\n\n");

}

void matrix_print(byte **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}