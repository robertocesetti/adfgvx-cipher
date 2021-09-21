//
// Created by Roberto Cesetti  on 19/09/2021.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "adfgvx.h"
#include "utils.h"


list_st *permutation(int s, int k, int nOfElement);

byte **create_matrix_from_array(byte *list);

byte *create_array(int nOfElement);

void genkey(const char *keyfile, int s1, int k1, int s2, int k2, int s3, int k3) {

    list_st *cList = permutation(s1, k1, 16);
    list_st *rList = permutation(s2, k2, 16);
    list_st *kList = permutation(s3, k3, 256);

    FILE *fd = fopen(keyfile, "w");
    fwrite(cList, sizeof(byte), 16, fd);
    fwrite(rList, sizeof(byte), 16, fd);
    fwrite(kList, sizeof(byte), 256, fd);
    fclose(fd);
/**
    list_print(cList);
    list_print(rList);
    list_print(kList);
*/
}

list_st *permutation(int s, int k, int nOfElement) {
    list_st *temp_list = create_list(nOfElement);
    list_st *list = empty_list();
    int c = s % nOfElement;
    int i = nOfElement - 1;
    while (i >= 0) {
        list = add(list, get(temp_list, c));
        temp_list = remove_value(temp_list, c);
        if (sizeof_list(temp_list) != 0) {
            c = (c + k) % sizeof_list(temp_list);
        }
        i--;
    }
    free(temp_list);
    return list;
}

byte *create_array(int nOfElement) {
    byte *array = calloc(nOfElement, sizeof(byte));
    for (int i = 0; i < nOfElement; i++) {
        array[i] = i;
    }
    return array;
}

byte **create_matrix_from_array(byte *list) {
    byte **matrix = calloc(16, sizeof(byte *));
    for (int i = 0; i < 16; i++) {
        matrix[i] = calloc(16, sizeof(byte));
        for (int j = 0; j < 16; j++) {
            matrix[i][j] = list[(i * 16) + j];
        }
    }
    free(list);
    return matrix;
}
