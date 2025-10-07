/**
 * @file vigenere.h
 * @brief Vigenère cipher API.
 *
 * Key is alphabetic; non-alphabetic characters in the message are preserved.
 */
#ifndef VIGENERE_H
#define VIGENERE_H

int vigenere_encrypt(const char *plaintext, const char *key, char *out);
int vigenere_decrypt(const char *ciphertext, const char *key, char *out);

#endif /* VIGENERE_H */
