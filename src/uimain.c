#include <stdio.h>
#include <stdlib.h>

#include "tokenizer.h"
#include "history.h"

int main(void) {
  int running = 1;
  
  // Maximum input string is 32.
  char *input;

  // Allocate memory for linked list.
  List *list = init_history();
  
  puts("Enter a string or 'o' for options.");
  
  while (running) {
    printf("> ");

    // Receive input from user and store in char *input.
    gets(input);

    // Echo input back to user.
    puts(input);
    
    if (input[0] == 'h' && input[1] == '\0') {
      // Show all available options to user.
      puts("!n - show history item n\ns - show all input history\nq - quit the program");
    } else if (input[0] == 's' && input[1] == '\0') {
      // Display all input history from user.
      print_history(list);
    } else if (input[0] == 'q' && input[1] == '\0') {
      // Free allocated memory within linked list.
      free_history(list);
      // Terminate the program.
      running = 0;
    } else if (input[0] == '!' && input[1] == '\0') {
      // Increase pointer by 1 since index 0 is '!'. 
      input++;
      // Convert string to int.
      int id = atoi(input);
      char *item = get_history(list, id);
      if (item != NULL) puts(item);
    } else {
      // Add input to linked list.
      add_history(list, input);
    }
  }
  
  return 0;
}
