//
// Created by Roberto Cesetti on 19/09/2021.
//

#ifndef ROBERTOCESETTI105114_ADFGVX_H
#define ROBERTOCESETTI105114_ADFGVX_H

/**
 * Generate the key file by using 3 pairs of values.
 *
 * @param key_file key file name.
 * @param s1 value of first pair.
 * @param k1 value of first pair.
 * @param s2 value of second pair.
 * @param k2 value of second pair.
 * @param s3 value of third pair.
 * @param k3 value of third pair.
 */
void genkey(const char *key_file, int s1, int k1, int s2, int k2, int s3, int k3);

/**
 * Encode the given input file by using the given key file and storing the result in the output_file.
 *
 * @param key_file key file name.
 * @param input_file input file name.
 * @param output_file output file name.
 */
void encode(char *key_file, char *input_file, char *output_file);

/**
 * Decode the given input file by using the given key file and storing the result in the output_file.
 *
 * @param key_file key file name.
 * @param input_file input file name.
 * @param output_file output file name.
 */
void decode(char *key_file, char *input_file, char *output_file);

#endif //ROBERTOCESETTI105114_ADFGVX_H
