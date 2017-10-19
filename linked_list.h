#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node {
  char name[256];
  char artist[256];
  struct node *next;
};

void print_list(struct node *);
struct node * insert_front(struct node *, char *, char *);
struct node * free_list(struct node *);
struct node * insert_order(struct node *, char *, char *);
struct node * find_song(struct node *, char *);
struct node * find_artist(struct node *, char *);
struct node * random_node(struct node *);
struct node * remove_node(struct node *, struct node *);
int length(struct node *);
int songcmp(struct node *, char *, char *);

void print_listh(struct node *head);
