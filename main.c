#include <stdio.h>
#include <string.h>
#include "adfgvx.h"

void print_help();

int main(int argc, char *argv[]) {
    if (argc == 9 && strcmp(argv[1], "genkey") == 0) {
        genkey(argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8]);
    } else if (argc == 5) {
        if (strcmp(argv[1], "encode") == 0) {
            encode(argv[2], argv[3], argv[4]);
        } else if (strcmp(argv[1], "decode") == 0) {
            decode(argv[2], argv[3], argv[4]);
        } else {
            perror("Incorrect values entered");
            return -3;
        }
    } else {
        print_help();
    }
    return 0;
}

void print_help() {
    printf("\nList of commands:\n");
    printf("1) genkey <keyfile> <s1> <k1> <s2> <k2> <s3> <k3>\n");
    printf("2) encode <keyfile> <inputfile> <outputfile>\n");
    printf("3) decode <keyfile> <inputfile> <outputfile>\n");
}
