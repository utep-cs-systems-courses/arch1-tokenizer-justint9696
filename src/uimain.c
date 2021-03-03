#include <stdio.h>
#include <string.h>

#include "tokenizer.h"
#include "history.h"

int main() {
  // Testing tokenizer.c
  
  char *str = "the cake is good";

  int test;
  char *test2;
  char **test3;
  
  test = space_char(' ');
  printf("space_char: %i\n", test);

  test = non_space_char('\t');
  printf("non_space_char: %i\n", test);

  test2 = word_start(str);
  printf("word_start: %s\n", test2);

  test2 = word_start(test2);
  printf("word_start: %s\n", test2);

  test2 = word_terminator(str);
  printf("word_terminator: %s\n", test2);

  test = count_words(str);
  printf("count_words: %i\n", test);

  test2 = copy_str("hello", 4);
  printf("copy_str: %p\n", (void*)&str);
  
  test2 = copy_str(str, 3);
  printf("copy_str: %p\n", (void*)&test2);

  test3 = tokenize(str);
  //printf("tokenize:\n");
  //for (int i = 0; i < 4; i++)
  //printf("%i: %s\n", i, test3[i]);

  print_tokens(test3);

  free_tokens(test3);
  
  // Testing history.c

  List *list = init_history();

  add_history(list, "hello");
  add_history(list, "world");

  print_history(list);
  
  return 0;
}
