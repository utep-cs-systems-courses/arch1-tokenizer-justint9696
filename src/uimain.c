#include <stdio.h>
#include <string.h>

#include "tokenizer.h"
#include "history.h"

int main(void) {
  int running = 1;
  
  // Maximum input string is 32.
  char input[32];

  // Allocate memory for linked list.
  List *list = init_history();
  
  printf("Enter a string or type 'help' for options.\n");
  
  while (running) {
    printf("> ");

    // Receive input from user and store in char *input.
    scanf("%s", input);

    // Echo input back to user.
    printf("%s\n", input);
    
    if (!strcmp(input, "help")) {
      // Show all available options to user.
      printf("history - show all input history\nquit - quit the program\n");
    } else if (!strcmp(input, "history")) {
      // Display all input history from user.
      print_history(list);
    } else if (!strcmp(input, "quit")) {
      // Free allocated memory within linked list.
      free_history(list);
      // Terminate the program.
      running = 0;
    } else if (input[0] == '!' && strlen(input) > 1) {
      // Cannot directly convert string to integer?
    } else {
      // Add input to linked list.
      add_history(list, input);
    }
  }
  
  return 0;
}
