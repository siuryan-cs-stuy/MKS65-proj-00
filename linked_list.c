#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

void print_list(struct node *head) {
  printf("[");
  while (head->next != NULL) {
    printf("%d,", head->i);
    head = head->next;
  }
  printf("%d]\n", head->i);
}

struct node * insert_front(struct node *head, int i) {
  struct node *new_head = (struct node*) malloc(sizeof(struct node));
  new_head->next = head;
  new_head->i = i;

  return new_head;
}

struct node * free_list(struct node *head) {
  struct node *temp = head;
  while (temp->next != NULL) {
    struct node *next = temp->next;
    free(temp);
    temp = next;
  }
  free(temp);
  return head;
}

