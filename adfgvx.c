//
// Created by Roberto Cesetti  on 19/09/2021.
//

#include <stddef.h>
#include <stdlib.h>
#include "adfgvx.h"
#include "utils.h"

list_st *permutation(list_st *list, int s, int k, int nOfElement);

byte encode_byte(int index_matrix, int index_file);

byte decode_byte(byte b, key_st *key, int k);

void genkey(const char *key_file, int s1, int k1, int s2, int k2, int s3, int k3) {
    if (s1 >= 0 && k1 >= 0 && s2 >= 0 && k2 >= 0 && s3 >= 0 && k3 >= 0) {
        list_st *temp_list = empty_list(), *key_list = empty_list();
        temp_list = concat_list(permutation(temp_list, s1, k1, 16), permutation(temp_list, s2, k2, 16));
        key_list = concat_list(temp_list, permutation(key_list, s3, k3, 256));
        file_write(key_list, key_file);
        dealloc_list_struct(temp_list);
        dealloc_list_struct(key_list);
    } else {
        perror("Incorrect values entered.\n");
        exit(-1);
    }
}

list_st *permutation(list_st *list, int s, int k, int nOfElement) {
    list_st *temp_list = empty_list();
    temp_list = create_list(temp_list, nOfElement);
    int c = s % nOfElement;
    int i = nOfElement - 1;
    while (i >= 0) {
        list = add(list, get_value(temp_list, c));
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
    list_st *input = empty_list();
    list_st *list_byte = empty_list();
    key_st *key = create_key_struct(NULL);
    input = read_file(input_file, input);
    key = read_key_file(key_file, key, input);
    int index_file = 0;
    list_st *reference_k = key->k;
    while (input != NULL) {
        list_byte = add(list_byte, encode_byte(get_index(reference_k, input->value), index_file));
        index_file++;
        input = input->next;
    }
    file_write(list_byte, output_file);
    dealloc_list_struct(input);
    dealloc_list_struct(list_byte);
    dealloc_key_struct(key);
}

byte encode_byte(int index_matrix, int index_file) {
    int i = index_matrix % 16;
    int j = index_matrix / 16;
    int index_c = ((i + index_file) % 16) * 16;
    int index_r = (j + index_file) % 16;
    return index_c + index_r;
}

void decode(char *key_file, char *input_file, char *output_file) {
    list_st *list_byte = empty_list(), *input = empty_list();
    key_st *key = create_key_struct(NULL);
    key = read_key_file(key_file, key, list_byte);
    input = read_file(input_file, input);
    int index = 0;
    while (input != NULL) {
        list_byte = add(list_byte, decode_byte(input->value, key, index));
        input = input->next;
        index++;
    }
    file_write(list_byte, output_file);
    dealloc_key_struct(key);
    dealloc_list_struct(input);
    dealloc_list_struct(list_byte);
}

byte decode_byte(byte b, key_st *key, int k) {
    byte v1 = b >> 4;
    byte v2 = b & 0x0f;
    int i = get_index(key->c, v1);
    int j = get_index(key->r, v2);
    int index_c = (i - k) % 16;
    int index_r = (j - k) % 16;
    int index_list = (index_r * 16) + index_c;
    list_st *list_key = key->k;
    return get_value(list_key, index_list);
}






