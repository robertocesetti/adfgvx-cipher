#include <stdio.h>
#include "adfgvx.h"

void print_help();

int main() {
    genkey("keyfile", 3, 5, 4, 7, 6, 7);
    //encode("keyfile", "inputfile.txt", "encoded");
    //decode("keyfile", "encoded", "decoded");
    return 0;
}

void print_help() {
    printf("\nList of commands:\n");
    printf("1) genkey <keyfile> <s1> <k1> <s2> <k2> <s3> <k3>\n");
    printf("2) encode <keyfile> <inputfile> <outputfile>\n");
    printf("3) decode <keyfile> <inputfile> <outputfile>\n");
}
