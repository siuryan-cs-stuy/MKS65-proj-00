#include "linked_list.h"

// Prints a list of nodes given head pointer
void print_list(struct node *head) {
  printf("[");
  print_listh(head);
  printf("]\n");
}

// Helper print function
void print_listh(struct node *head) {
  while (head) {
    printf("%s by %s, ", head->name, head->artist);
    head = head->next;
  }
}

// Inserts node in front of linked list
struct node * insert_front(struct node *head, char *name, char *artist) {
  struct node *new_head = (struct node*) malloc(sizeof(struct node));
  new_head->next = head;
  strcpy(new_head->name, name);
  strcpy(new_head->artist, artist);

  return new_head;
}

// Frees the memory for a linked list
struct node * free_list(struct node *head) {
  while (head) {
    struct node *next = head->next;
    free(head);
    head = next;
  }
  return 0;
}

// Compares two songs
int songcmp(struct node *head, char *song, char *artist) {
  if (strcmp(head->artist, artist) == 0) {
    return strcmp(head->name, song);
  }
  return strcmp(head->artist, artist);
}

// Insert node into its proper place in the linked list
// Assumes that the list is already properly ordered
struct node * insert_order(struct node *head, char *song, char *artist) {
  struct node *temp = head;
  struct node *trail = head;
  if(head == 0 || songcmp(head, song, artist) > 0){
    return insert_front(head, song, artist);
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
  trail->next = insert_front(head, song, artist);
  return temp;
}

// Finds and returns the pointer to a song
struct node * find_song(struct node *head, char *song) {
  while (head) {
    if (strcmp(head->name, song) == 0) {
      return head;
    }
    head = head->next;
  }
  return 0;
}

// Finds and returns the pointer to the first song with the specified artist
struct node * find_artist(struct node *head, char *artist) {
  while (head) {
    if (strcmp(head->artist, artist) == 0) {
      return head;
    }
    head = head->next;
  }
  return 0;
}

// Returns the length of the linked list
int length(struct node *head) {
  int i = 0;
  while (head) {
    i++;
    head = head->next;
  }
  return i;
}

// Returns a pointer to a random node
struct node * random_node(struct node *head) {
  int node_num = 0;
  if (length(head) > 0) {
    node_num = rand() % length(head);
  }
  while (node_num > 0) {
    head = head->next;
    node_num--;
  }
  return head;
}

// Removes a node from the linked list
struct node * remove_node(struct node *head, struct node *song) {
  struct node *trail = head;
  struct node *temp = head;
  while (temp) {
    if (songcmp(temp, song->name, song->artist) != 0) {
      trail = temp;
      temp = temp->next;
    }
    else {
      trail->next = song->next;
      free(song);
      return head;
    }
  }
  return head;  
}
