#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

void print_list(struct node *head) {
  printf("[");
  while (head->next != NULL) {
    printf("%s by %s, ", head->name, head->artist);
    head = head->next;
  }
  printf("%s by %s]\n", head->name, head->artist);
}

struct node * insert_front(struct node *head, char *name, char *artist) {
  struct node *new_head = (struct node*) malloc(sizeof(struct node));
  new_head->next = head;
  strcpy(new_head->name, name);
  strcpy(new_head->artist, artist);

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
  return 0;
}
//helper funtion to compare two nodes
int nodecmp(struct node *first, struct node *second){
  printf("MADE %d\n", strcmp(first->name, second->name));
  if (strcmp(first->name, second->name) != 0)
    printf("HERE\n");
    return strcmp(first->artist, second->artist);
  return strcmp(first->name, second->name); 
}

struct node * insert_order(struct node *head, char *name, char *artist){
  struct node *temp = (struct node*) malloc(sizeof(struct node));
  strcpy(temp->name, name);
  strcpy(temp->artist, artist);
  printf("HERE!\n");
  while(temp->next != 0 && nodecmp(head, temp) < 0){
    printf("LOOKIE HERE: %d\n",(nodecmp(head,temp)));
    temp = temp->next;
  }
  head->next = temp->next;
  temp->next = head;
  return head;
}
