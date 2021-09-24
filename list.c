//
// Created by Roberto Cesetti on 22/09/2021.
//
#include <stddef.h>
#include <stdlib.h>
#include "list.h"

list_st *allocate_node(byte value);

list_st *empty_list() {
    return NULL;
}

list_st *create_list(list_st *list, int nElements) {
    int i = --nElements;
    if (list != NULL) {
        list = dealloc_list_struct(list);
    }
    list_st *el1;
    while (i >= 0) {
        el1 = malloc(sizeof(list_st));
        el1->value = i;
        el1->next = list;
        list = el1;
        i--;
    }
    return list;
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

list_st *allocate_node(byte value) {
    list_st *node = malloc(sizeof(list_st));
    node->value = value;
    node->next = NULL;
    return node;
}

list_st *remove_value(list_st *list, int index) {
    list_st *scanner = list;
    if (index == 0) {
        return remove_head(list);
    }
    while ((index) != 1) {
        scanner = scanner->next;
        index--;
    }
    list_st *temp = scanner->next->next;
    free(scanner->next);
    scanner->next = temp;
    return list;
}

list_st *remove_head(list_st *list) {
    list_st *temp = list->next;
    free(list);
    return temp;
}

list_st *concat_list(list_st *first_list, list_st *second_list, list_st *third_list) {
    if (first_list == NULL && second_list == NULL && third_list == NULL) {
        return NULL;
    } else {
        list_st *result = first_list;
        list_st *temp = second_list;
        list_st *temp2 = third_list;
        int i = 0;
        while (temp != NULL) {
            result = add(result, temp->value);
            temp = temp->next;
            if (temp == NULL && i == 0) {
                temp = temp2;
                i++;
            }
        }
        return first_list;
    }
}

byte get_value(list_st *list, int index) {
    list_st *scanner = list;
    while (index != 0) {
        scanner = scanner->next;
        index--;
    }
    return scanner->value;
}

int get_index(list_st *list, byte value) {
    int index = 0;
    while (list != NULL) {
        if (list->value == value) {
            break;
        }
        index++;
        list = list->next;
    }
    return index;
}

list_st *dealloc_list_struct(list_st *list) {
    if (list != NULL) {
        dealloc_list_struct(list->next);
        free(list);
    }
    return empty_list();
}