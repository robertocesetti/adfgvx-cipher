//
// Created by Roberto Cesetti on 24/09/2021.
//

#include <stdlib.h>
#include "fileoperation.h"

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
    if (list != NULL) {
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
        perror("Unable to open file.\n");
        exit(-1);
    }
}