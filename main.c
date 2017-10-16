#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

int main() {
  // Create new head node
  struct node *head = (struct node*) malloc(sizeof(struct node));

  printf("Creating linked list...\n");
  printf("Setting head value to 5...\n");
  head->i = 5;

  print_list(head);

  printf("Inserting node with value 15...\n");
  head = insert_front(head, 15);
  printf("Inserting node with value 0...\n");
  head = insert_front(head, 0);
  printf("Inserting node with value -2...\n");
  head = insert_front(head, -2);
  
  print_list(head);

  printf("Freeing memory from head pointer...\n");
  head = free_list(head);
  print_list(head);
  
  return 0;
}
