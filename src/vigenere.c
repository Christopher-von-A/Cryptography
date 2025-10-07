#include "vigenere.h"
#include <ctype.h>
#include <string.h>

static int normalize_key(const char *key, int *shifts, int maxlen) {
  int count = 0;
  for (int i = 0; key[i] != '\0' && count < maxlen; ++i) {
    if (isalpha((unsigned char)key[i])) {
      shifts[count++] = toupper((unsigned char)key[i]) - 'A';
    }
  }
  return count;
}

int vigenere_encrypt(const char *plaintext, const char *key, char *out) {
  if (!plaintext || !key || !out)
    return -1;
  int shifts[256];
  int n = normalize_key(key, shifts, 256);
  if (n == 0)
    return -1;
  int ki = 0;
  size_t len = strlen(plaintext);
  for (size_t i = 0; i < len; ++i) {
    unsigned char c = plaintext[i];
    if (isalpha(c)) {
      int shift = shifts[ki % n];
      if (isupper(c))
        out[i] = 'A' + ((c - 'A' + shift) % 26);
      else
        out[i] = 'a' + ((c - 'a' + shift) % 26);
      ki++;
    } else
      out[i] = c;
  }
  out[len] = '\0';
  return 0;
}

int vigenere_decrypt(const char *ciphertext, const char *key, char *out) {
  if (!ciphertext || !key || !out)
    return -1;
  int shifts[256];
  int n = normalize_key(key, shifts, 256);
  if (n == 0)
    return -1;
  int ki = 0;
  size_t len = strlen(ciphertext);
  for (size_t i = 0; i < len; ++i) {
    unsigned char c = ciphertext[i];
    if (isalpha(c)) {
      int shift = shifts[ki % n];
      if (isupper(c))
        out[i] = 'A' + ((c - 'A' - shift + 26) % 26);
      else
        out[i] = 'a' + ((c - 'a' - shift + 26) % 26);
      ki++;
    } else
      out[i] = c;
  }
  out[len] = '\0';
  return 0;
}
