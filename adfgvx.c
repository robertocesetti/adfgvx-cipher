//
// Created by Roberto Cesetti  on 19/09/2021.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "adfgvx.h"
#include "utils.h"


int *permutation(int s, int k, int nOfElement);

int **createMatrixFromArray(int *list);

int *createArray(int nOfElement);

void genkey(const char *keyfile, int s1, int k1, int s2, int k2, int s3, int k3) {

    int *column = permutation(s1, k1, 16);
    int *row = permutation(s2, k2, 16);
    int *key = permutation(s3, k3, 256);
    int **kMatrix = createMatrixFromArray(key);
    FILE *fd = fopen(keyfile, "wb+");
    fwrite(column, sizeof(char), 1, fd);
    fwrite(row, sizeof(char), 1, fd);
    fwrite(key, sizeof(char), 1, fd);
    fclose(fd);
}


int *permutation(int s, int k, int nOfElement) {
    int *newArray = createArray(nOfElement);
    int *emptyArray = calloc(nOfElement, sizeof(int));
    int c = s % nOfElement;
    int i = nOfElement - 1;
    while (i >= 0) {
        emptyArray[i] = newArray[c];
        c = (c + k) % nOfElement;
        i--;
    }
    free(newArray);
    return emptyArray;
}

int *createArray(int nOfElement) {
    int *array = calloc(nOfElement, sizeof(int));
    for (int i = 0; i < nOfElement; i++) {
        array[i] = i;
    }
    return array;
}

int **createMatrixFromArray(int *list) {
    int **matrix = calloc(16, sizeof(int *));
    for (int i = 0; i < 16; i++) {
        matrix[i] = calloc(16, sizeof(int));
        for (int j = 0; j < 16; j++) {
            matrix[i][j] = list[(i * 16) + j];
        }
    }
    free(list);
    return matrix;
}
