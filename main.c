#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

int main() {
  // Create new head node
  struct node *head = (struct node*) malloc(sizeof(struct node));

  printf("=============================\n");
  printf("TESTING LINKED LIST FUNCTIONS\n");
  printf("=============================\n");

  printf("\n");
  printf("Creating linked list...\n");
  printf("Setting song name to 'Shape of You'...\n");
  strcpy(head->name, "Shape of You");
  strcpy(head->artist, "Ed Sheeran");

  head =insert_front(head, "Airplanes", "B.O.B");

  head->next = 0;


  print_list(head);
  printf("\n");
  
  printf("Inserting song 'Galway Girl'...\n");
  head = insert_order(head, "Galway Girl", "Ed Sheeran");

  printf("Inserting song 'Best'...\n");
  head = insert_order(head, "Best", "Best");


  printf("Inserting song 'Test'...\n");
  head = insert_order(head, "Test", "test");

  printf("Inserting song 'Perfect'...\n");
  head = insert_order(head, "Perfect", "Ed Sheeran");

  
  print_list(head);
  printf("\n");

  /*
  printf("Finding song 'Test'...\n");
  print_list(find_song(head, "Test"));
  
  printf("Finding song 'DNE'...\n");
  print_list(find_song(head, "DNE"));
  printf("\n");
  
  printf("Finding artist 'Ed Sheeran'...\n");
  print_list(find_artist(head, "Ed Sheeran"));
  printf("\n");
  */  

  printf("Freeing memory from head pointer...\n");
  head = free_list(head);
  
  return 0;
}
