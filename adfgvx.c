//
// Created by Roberto Cesetti  on 19/09/2021.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "adfgvx.h"
#include "utils.h"


int *permutation(int s, int k, int nOfElement);

int **createMatrixFromList(int *list);

int *createArray(int nOfElement);

void writeMatrix(int **matrix, FILE *file, int nOfElements);

void genkey(const char *keyfile, int s1, int k1, int s2, int k2, int s3, int k3) {

    int *cList = permutation(s1, k1, 16);
    int *rList = permutation(s2, k2, 16);
    int *kList = permutation(s3, k3, 256);
    int **kMatrix = createMatrixFromList(kList);
    FILE *fd = fopen(keyfile, "wb+");
    fwrite(cList, sizeof(char), 1, fd);
    fwrite(rList, sizeof(char), 1, fd);
    //WRITE-LIST
    fwrite(kList, sizeof(char), 1, fd);
    //WRITE-MATRIX
    writeMatrix(kMatrix, fd, 16);
    fclose(fd);
}

void writeMatrix(int **matrix, FILE *file, int nOfElements) {
    for (int i = 0; i < nOfElements; i++) {
        for (int j = 0; j < nOfElements; j++) {
            //DUBBIO: &matrix[i][j]
            fprintf(file,"%c", matrix[i][j]);
            //fwrite(&matrix[i][j], sizeof(char), 1, file);
        }
        fprintf(file, "%s", "\n");
    }
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

int **createMatrixFromList(int *list) {
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
