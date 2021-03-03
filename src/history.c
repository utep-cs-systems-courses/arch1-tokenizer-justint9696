#include <string.h>
#include "history.h"

List *init_history() {
  // Initializes a linked list.
  List *list;
  list->root = NULL;
  return list;
}

void add_history(List *list, char *str) {
  Item *tmp;
  int id = 0;
  if (list->root != NULL) {
    printf("Root is not NULL; adding item\n");
    tmp = list->root;
    while (tmp->next) {
      id++;
      tmp = tmp->next;
    }
    Item* item = { id, str, NULL };
    tmp->next = item;
  } else {
    printf("Root is NULL\n");
    Item *item = { id, str, NULL };
    list->root = item;
  }
}

void print_history(List *list) {
  Item *tmp = list->root;
  printf("Contents of List:\n");
  while (tmp->next) {
    printf("%i: %s", tmp->id, tmp->str);
    tmp = tmp->next;
  }
}
