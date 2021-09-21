//
// Created by Roberto Cesetti  on 19/09/2021.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "adfgvx.h"
#include "utils.h"


int *permutation(int s, int k, int nOfElement);

int *createArray(int nOfElement);

void write(const char *filename, int *data, int size);

int *read(const char *file);

int **createMatrixFromArray(int *list);


void genkey(const char *keyfile, int s1, int k1, int s2, int k2, int s3, int k3) {

    write(keyfile, permutation(s1, k1, 16), 16);
    write(keyfile, permutation(s2, k2, 16), 16);
    write(keyfile, permutation(s3, k3, 256), 256);
    /**
      arrayPrint(permutation(s1, k1, 16), 16);
      arrayPrint(permutation(s2, k2, 16), 16);
      matrixPrint(createMatrixFromArray(permutation(s3, k3, 256)), 16);
   */
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

void write(const char *filename, int *data, int size){
    FILE *fd = fopen(filename, "wb");
    fwrite(data, sizeof(char), size, fd);

    fclose(fd);
}

int *read(const char *file) {
    FILE *fd = fopen(file, "rb");
    int *values;
    fread(&values, sizeof(char), 1, fd);
    return values;
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