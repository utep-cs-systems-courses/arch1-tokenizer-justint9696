#include <string.h>
#include "history.h"

List *init_history() {
  // Initializes a linked list and sets the root to NULL.
  List *list;
  list->root = NULL;
  return list;
}

void add_history(List *list, char *str) {
  // Adds item to linked list.
  int id = 0;
  Item *item = (Item *)malloc(sizeof(Item));

  // If the root is NULL, then no root has been assigned; assign item at root.
  // If not, then find the first node that is NULL and assign the item to that node.
  if (list->root == NULL) {
    item->id = id;
    item->str = str;
    item->next = NULL;
    list->root = item;
  } else { 
    id++;
    Item *tmp = list->root;
    while (tmp->next != NULL) {
      id++;
      tmp = tmp->next;
    }
    item->id = id;
    item->str = str;
    item->next = NULL;
    tmp->next = item;
  }
}

char *get_history(List *list, int id) {
  // Finds and returns the given id within the linked list. Returns NULL if id not found.
  Item *tmp = list->root;
  while (id-- && tmp != NULL) {
    tmp = tmp->next;
  }
  if (tmp == NULL) {
    printf("Item could not be found.\n");
    return NULL;
  }
  return tmp->str;
}

void print_history(List *list) {
  // Prints every item of the linked list.
  Item *tmp = list->root;
  printf("Contents of List:\n");
  while (tmp != NULL) {
    printf("%i: %s\n", tmp->id, tmp->str);
    tmp = tmp->next;
  }
  printf("End of Contents\n");
}

void free_history(List *list) {
  // Frees space of every item with allocated memory.
  Item *tmp = list->root;
  Item *item;
  while (tmp != NULL) {
    item = tmp;
    tmp = tmp->next;
    free(item);
  }
}
