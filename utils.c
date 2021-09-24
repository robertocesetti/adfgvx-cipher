//
// Created by Roberto Cesetti on 20/09/2021.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

key_st *create_key_struct(key_st *k) {
    if (k == NULL) {
        perror("Unable to allocate memory");
    }
    k->c = NULL;
    k->r = NULL;
    k->k = NULL;
    return k;
}

void dealloc_key_struct(key_st *key_st) {
    key_st->c = dealloc_list_struct(key_st->c);
    key_st->r = dealloc_list_struct(key_st->r);
    key_st->k = dealloc_list_struct(key_st->k);
    free(key_st);
}

void file_write(list_st *data, const char *file_name) {
    FILE *writing_file = fopen(file_name, "wb");
    check_file(writing_file);
    while (data != NULL) {
        fputc(data->value, writing_file);
        data = data->next;
    }
    fclose(writing_file);
}

key_st *read_key_file(key_st *key, char *file, list_st *list) {
    list = read_file(file, list);
    int i = 0;
    int size = sizeof_list(list);
    key = create_key_struct(key);
    while (i < size) {
        if (i < 16) {
            key->c = add(key->c, list->value);
        } else if (i < 32) {
            key->r = add(key->r, list->value);
        } else {
            key->k = add(key->k, list->value);
        }
        list = list->next;
        i++;
    }
    return key;
}

list_st *read_file(char *file, list_st *list) {
    if(list != NULL){
        list = empty_list();
    }
    FILE *reading_file = fopen(file, "rb");
    check_file(reading_file);
    int size = file_size(reading_file);
    while (size != 0) {
        list = add(list, fgetc(reading_file));
        size--;
    }
    fclose(reading_file);
    return list;
}

int file_size(FILE *file) {
    fseek(file, 0L, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}

void check_file(const FILE *file) {
    if (file == NULL) {
        /* File not created */
        perror("Unable to open file.\n");
        exit(-1);
    }
}

int module(int val1, int val2){
    int result = val1 % val2;
    return result < 0 ? result + val2 : result;
}

/************************** TODO.ELIMINARE **************************/


void list_print(list_st *l) {
    while (l != NULL) {
        printf("%d ", l->value);
        l = l->next;
    }
    printf("\n\n");
}
/**
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
 */