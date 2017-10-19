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
int songcmp(struct node *head, char *song, char *artist) {
  if (strcmp(head->artist, artist) == 0) {
    return strcmp(head->name, song);
  }
  return strcmp(head->artist, artist);
}

/*
struct node * insert_order(struct node *head, char *name, char *artist){
  struct node *temp = (struct node*) malloc(sizeof(struct node));
  while(nodecmp(head, temp) > 0){
    temp = temp->next;
  }
  head->next = temp->next;
  temp->next = head;
}
*/

struct node * insert_order(struct node *head, char *song, char *artist) {
  struct node *temp = head;
  struct node *trail = head;
  if (songcmp(head, song, artist) > 0) {
    struct node *test = insert_front(head, song, artist);
    return test;
  }
  while (head) {
    if (songcmp(head, song, artist) < 0) {
      // continue
      trail = head;
      head = head->next;
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
