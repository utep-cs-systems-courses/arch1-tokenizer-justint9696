#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tokenizer.h"

int space_char(char c) {
  return c == '\0' ? 0 : (c == ' ' || c == '\t');
}

int non_space_char(char c) {
  return c == '\0' ? 0 : (c != ' ' && c != '\t');
}

char *word_start(char *str) {
  // Receives a string and returns a pointer to its next word.
  char c;
  int n = -1;
  do {
    n++;
    c = str[n];
  } while (non_space_char(c));
  // If current char equals zero terminator where a space should be, return the string.
  if (str[n] == '\0') return str;
  while (n-- > -1) str++;
  return str;
}

char *word_terminator(char *str) {
  // Receives a string and returns a pointer to the char after the word.
  char c = str[0];
  while (non_space_char(c)) {
    str++;
    c = str[0];
  }
  return str;
}

int count_words(char *str) {
  // Receives a string and returns the number of words it contains.
  char c;
  int count = 1;
  // Determines number of words based on number of spaces.
  do {
    c = str[0];
    str++;
    if (space_char(c)) count++;
  } while (*str);
  return count;
}

char *copy_str(char *inStr, short len) {
  // Creates a new string of length 'len' and contains 'len' chars from the string and return it.
  char *outStr = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    outStr[i] = inStr[i];
  }
  outStr[len] = '\0';
  return outStr;
}

char **tokenize(char *str) {
  int size = count_words(str);
  char **t = malloc((size + 1) * sizeof(char*));
  char *tmp;
  for (int i = 0; i < size; i++) {
    tmp = word_terminator(str);
    t[i] = copy_str(str, tmp - str);
    str = word_start(str);
  }
  return t;
}

void print_tokens(char **tokens) {
  printf("Tokens:\n");
  int n = 0;
  for (char **tmp = tokens; tmp[0] != NULL; *tmp++, n++) {
    printf("%i: %s\n", n, tmp[0]);
  }
}

void free_tokens(char **tokens) {
  for (char **tmp = tokens; tmp[0] != NULL; *tmp++) {
    free(tmp[0]);
  }
  free(tokens);
}
