#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

void print_list(struct node *head) {
  printf("[");
  while (head) {
    printf("%s by %s, ", head->name, head->artist);
    head = head->next;
  }
  printf("]\n");
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
  while (temp->next) {
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

/*
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
*/

struct node * insert_order(struct node *head, char *song, char *artist) {
  struct node *temp = head;
  struct node *trail = head;
  head = head->next;
  if (!head) {
    if (strcmp(trail->artist, artist) > 0) {
      return insert_front(trail, song, artist);
    }
    else {
      trail->next= insert_front(head, song, artist);
      return temp;
    }
  }
  while (head) {
    if (strcmp(head->artist, artist) == 0) {
      if (strcmp(head->name, song) < 0) {
	// continue
	head = head->next;
	trail = trail->next;
      }
      else {
	// insert before head
	trail->next = insert_front(head, song, artist);
	return temp;
      }
    }
    else if (strcmp(head->artist, artist) < 0) {
      // continue
      head = head->next;
      trail = trail->next;
    }
    else {
      // insert before head
      trail->next = insert_front(head, song, artist);
      return temp;
    }
  }
}

struct node * find_song(struct node *head, char *song) {
  while (head) {
    if (strcmp(head->name, song) == 0) {
      return head;
    }
    head = head->next;
  }
  return 0;
}

struct node * find_artist(struct node *head, char *artist) {
  while (head) {
    if (strcmp(head->artist, artist) == 0) {
      return head;
    }
    head = head->next;
  }
  return 0;
}
