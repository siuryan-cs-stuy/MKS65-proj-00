#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

int main() {
  // Create new head node
  struct node *head = (struct node*) malloc(sizeof(struct node));

  printf("Creating linked list...\n");
  printf("Setting song name to 'Shape of You'...\n");
  strcpy(head->name, "Shape of You");
  strcpy(head->artist, "Ed Sheeran");

  print_list(head);

  printf("Inserting song 'Test'...\n");
  head = insert_front(head, "Test", "test");
  
  print_list(head);

  printf("Freeing memory from head pointer...\n");
  head = free_list(head);
  
  return 0;
}
