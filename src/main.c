#include "caesar.h"
#include "cli.h"
#include "vigenere.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_TEXT 8192

void print_usage(const char *progname) {
  printf("Usage:\n");
  printf("  %s caesar -e|-d <key:int> \"text\"\n", progname);
  printf("  %s vigenere -e|-d <key:string> \"text\"\n", progname);
}

int main(int argc, char **argv) {
  if (argc < 4) {
    print_usage(argv[0]);
    return 1;
  }

  const char *cipher = argv[1];
  const char *mode = argv[2];

  if (strcmp(cipher, "caesar") == 0) {
    if (argc < 5) {
      print_usage(argv[0]);
      return 1;
    }
    int key = atoi(argv[3]);
    const char *text = argv[4];

    set_caesar_key(key);
    char *out = NULL;
    if (strcmp(mode, "-e") == 0) {
      out = caesar_encrypt((char *)text);
    } else if (strcmp(mode, "-d") == 0) {
      out = caesar_decrypt((char *)text);
    } else {
      print_usage(argv[0]);
      return 1;
    }

    if (out) {
      puts(out);
      free(out);
    } else {
      fprintf(stderr, "Error: caesar returned NULL\n");
      return 2;
    }
  } else if (strcmp(cipher, "vigenere") == 0) {
    if (argc < 5) {
      print_usage(argv[0]);
      return 1;
    }
    const char *key = argv[3];
    const char *text = argv[4];
    char out[MAX_TEXT];
    int res;
    if (strcmp(mode, "-e") == 0)
      res = vigenere_encrypt(text, key, out);
    else if (strcmp(mode, "-d") == 0)
      res = vigenere_decrypt(text, key, out);
    else {
      print_usage(argv[0]);
      return 1;
    }

    if (res == 0)
      puts(out);
    else {
      fprintf(stderr, "Vigenere error: invalid key\n");
      return 2;
    }
  } else {
    print_usage(argv[0]);
    return 1;
  }

  return 0;
}
