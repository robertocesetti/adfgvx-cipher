//
// Created by Roberto Cesetti  on 19/09/2021.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "adfgvx.h"
#include "utils.h"


list_st *permutation(int s, int k, int nOfElement);

void genkey(const char *keyfile, int s1, int k1, int s2, int k2, int s3, int k3) {
    if(keyfile == NULL){
        keyfile = "default_file";
    }
    if(s1 >= 0 && k1 >= 0 && s2 >= 0 && k2 >= 0 && s3 >= 0 && k3 >= 0){
        list_st *temp_list = concat_list(permutation(s1, k1, 16), permutation(s2, k2, 16));
        list_st *key_list = concat_list(temp_list, permutation(s3, k3, 256));
        file_write(key_list, keyfile);
    } else {
        printf("Incorrect values entered.\n");
        exit(EXIT_FAILURE);
    }

//    list_print(cList);
//    list_print(rList);
//    list_print(kList);

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



