//
// Created by Roberto Cesetti on 19/09/2021.
//

#ifndef ROBERTOCESETTI105114_ADFGVX_H
#define ROBERTOCESETTI105114_ADFGVX_H

/**
 * Generate the key file by using 3 pairs of values.
 *
 * @param key_file Key file name.
 * @param s1 Value of first pair.
 * @param k1 Value of first pair.
 * @param s2 Value of second pair.
 * @param k2 Value of second pair.
 * @param s3 Value of third pair.
 * @param k3 Value of third pair.
 */
void genkey(const char *key_file, char *s1, char *k1, char *s2, char *k2, char *s3, char *k3);

/**
 * Encode the given input file by using the given key file and storing the result in the output file.
 *
 * @param key_file Key file name.
 * @param input_file Input file name.
 * @param output_file Output file name.
 */
void encode(char *key_file, char *input_file, char *output_file);

/**
 * Decode the given input file by using the given key file and storing the result in the output file.
 *
 * @param key_file Key file name.
 * @param input_file Input file name.
 * @param output_file Output file name.
 */
void decode(char *key_file, char *input_file, char *output_file);

#endif //ROBERTOCESETTI105114_ADFGVX_H
