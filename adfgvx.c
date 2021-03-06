//
// Created by Roberto Cesetti  on 19/09/2021.
//

#include <stddef.h>
#include <stdlib.h>
#include "adfgvx.h"
#include "key.h"
#include "fileoperation.h"

list_st *permutation(list_st *list, int s, int k, int nOfElement);

void encode_file(list_st *input, key_st *key, FILE *output);

byte encode_byte(key_st *key, int index_matrix, int index_file);

void decode_file(list_st *input, key_st *key, FILE *output);

byte decode_byte(key_st *key, byte b, int k);

/**
 * Calculate the math module.
 *
 * @param val1 First value.
 * @param val2  Second value.
 * @return The module between the first and the second value.
 */
int module(int val1, int val2);

void genkey(const char *key_file, char *s1, char *k1, char *s2, char *k2, char *s3, char *k3) {
    if (s1 >= 0 && k1 >= 0 && s2 >= 0 && k2 >= 0 && s3 >= 0 && k3 >= 0) {
        list_st *list_key = empty_list(), *temp1 = empty_list(), *temp2 = empty_list();
        list_key = concat_list(permutation(list_key, strtol(s1, NULL, 36), strtol(k1, NULL, 36), 16),
                               permutation(temp1, strtol(s2, NULL, 36), strtol(k2, NULL, 36), 16),
                               permutation(temp2, strtol(s3, NULL, 36), strtol(k3, NULL, 36), 256));
        file_write(list_key, key_file);
        dealloc_list_struct(list_key);
        dealloc_list_struct(temp1);
        dealloc_list_struct(temp2);
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
    FILE *output = fopen(output_file, "wb");
    check_file(output);
    list_st *input = empty_list(), *list_key = empty_list();
    key_st *key = malloc(sizeof(key_st));
    key = read_key_file(key, key_file, list_key);
    input = read_file(input_file, input);
    encode_file(input, key, output);
    dealloc_list_struct(input);
    dealloc_list_struct(list_key);
    dealloc_key_struct(key);
    fclose(output);
}

void encode_file(list_st *input, key_st *key, FILE *output) {
    int index_file = 0;
    while (input != NULL) {
        fputc(encode_byte(key, get_index(key->k, input->value), index_file), output);
        index_file++;
        input = input->next;
    }
}

byte encode_byte(key_st *key, int index_matrix, int index_file) {
    int i = index_matrix % 16;
    int j = index_matrix / 16;
    int index_c = (module((i + index_file), 16));
    byte bc = (get_value(key->c, index_c)) * 16;
    int index_r = module((j + index_file), 16);
    byte br = get_value(key->r, index_r);
    return bc | br;
}

void decode(char *key_file, char *input_file, char *output_file) {
    FILE *output = fopen(output_file, "wb");
    check_file(output);
    list_st *input = empty_list(), *list_key = empty_list();
    key_st *key = malloc(sizeof(key_st));
    key = read_key_file(key, key_file, list_key);
    input = read_file(input_file, input);
    decode_file(input, key, output);
    dealloc_list_struct(input);
    dealloc_list_struct(list_key);
    dealloc_key_struct(key);
    fclose(output);
}

void decode_file(list_st *input, key_st *key, FILE *output) {
    int index_file = 0;
    while (input != NULL) {
        fputc(decode_byte(key, input->value, index_file), output);
        input = input->next;
        index_file++;
    }
}

byte decode_byte(key_st *key, byte b, int k) {
    byte v1 = b >> 4;
    byte v2 = b & 0x0f;
    int i = get_index(key->c, v1);
    int j = get_index(key->r, v2);
    int index_c = module((i - k), 16);
    int index_r = module((j - k), 16);
    int index_list = (index_r * 16) + index_c;
    list_st *list_key = key->k;
    return get_value(list_key, index_list);
}

int module(int val1, int val2) {
    int result = val1 % val2;
    return result < 0 ? result + val2 : result;
}



