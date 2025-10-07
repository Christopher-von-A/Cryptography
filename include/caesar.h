/**
 * @file caesar.h
 * @brief Caesar cipher interface (encrypt/decrypt using global key).
 *
 * The key is set with set_caesar_key() and both encrypt/decrypt functions
 * return newly allocated strings which the caller must free().
 */

#ifndef CAESAR_H
#define CAESAR_H

#include <stddef.h>

void set_caesar_key(int key); /* set global key (normalized internally) */
char *
caesar_encrypt(char *plaintext); /* returns malloc'ed string (caller frees) */
char *
caesar_decrypt(char *ciphertext); /* returns malloc'ed string (caller frees) */

#endif /* CAESAR_H */
