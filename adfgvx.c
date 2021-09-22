//
// Created by Roberto Cesetti  on 19/09/2021.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "adfgvx.h"
#include "utils.h"

list_st *permutation(int s, int k, int nOfElement);

void genkey(const char *key_file, int s1, int k1, int s2, int k2, int s3, int k3) {
    if (key_file == NULL) {
        key_file = "default_file";
    }
    if (s1 >= 0 && k1 >= 0 && s2 >= 0 && k2 >= 0 && s3 >= 0 && k3 >= 0) {
        list_st *temp_list = concat_list(permutation(s1, k1, 16), permutation(s2, k2, 16));
        list_st *key_list = concat_list(temp_list, permutation(s3, k3, 256));
        file_write(key_list, key_file);
    } else {
        perror("Incorrect values entered.\n");
        exit(-1);
    }
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

void encode(char *key_file, char *input_file, char *output_file) {
    FILE *file_k = read_input_file(key_file);
    FILE *file_i = read_input_file(input_file);
    fclose(file_k);
    fclose(file_i);
}


void decode(char *key_file, char *input_file, char *output_file) {

}



