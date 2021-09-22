//
// Created by Roberto Cesetti on 20/09/2021.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

void file_write(list_st *data, const char *file_name) {
    FILE *writing_file = fopen(file_name, "wb");
    if (writing_file == NULL) {
        /* File not created */
        perror("Unable to open file.\n");
        exit(-1);
    }
    while (data != NULL) {
        fputc(data->value, writing_file);
        data = data->next;
    }
    fclose(writing_file);
}

FILE *read_input_file (char *file){
    FILE *reading_file = fopen(file, "rb");
    check_file(reading_file);
    fseek(reading_file, 0, SEEK_SET);
    return reading_file;
}

void check_file(const FILE *file) {
    if (file == NULL) {
        /* File not created */
        perror("Unable to open file.\n");
        exit(-1);
    }
}

/************************** TODO.CONTROLLARE *************************/

int module(int val1, int val2) {
    int result = val1 % val2;

}

int absolute_value(int val) {

}

/************************** TODO.ELIMINARE **************************/

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