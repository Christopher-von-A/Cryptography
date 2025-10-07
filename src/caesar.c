#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int g_caesar_key = 0;

void set_caesar_key(int key) {
  /* normalize into range -25..25 (we keep sign to make decrypt easy) */
  g_caesar_key = key % 26;
}

static char shift_char(char c, int k) {
  if ('A' <= c && c <= 'Z') {
    int base = 'A';
    int pos = c - base;
    pos = (pos + k + 26) % 26;
    return (char)(base + pos);
  } else if ('a' <= c && c <= 'z') {
    int base = 'a';
    int pos = c - base;
    pos = (pos + k + 26) % 26;
    return (char)(base + pos);
  }
  return c;
}

char *caesar_encrypt(char *plaintext) {
  if (!plaintext)
    return NULL;
  size_t len = strlen(plaintext);
  char *out = malloc(len + 1);
  if (!out)
    return NULL;
  for (size_t i = 0; i < len; ++i)
    out[i] = shift_char(plaintext[i], g_caesar_key);
  out[len] = '\0';
  return out;
}

char *caesar_decrypt(char *ciphertext) {
  if (!ciphertext)
    return NULL;
  size_t len = strlen(ciphertext);
  char *out = malloc(len + 1);
  if (!out)
    return NULL;
  for (size_t i = 0; i < len; ++i)
    out[i] = shift_char(ciphertext[i], -g_caesar_key);
  out[len] = '\0';
  return out;
}
