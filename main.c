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
  //first song in list
  strcpy(head->name, "Shape of You");
  strcpy(head->artist, "Ed Sheeran");
  head->next = 0;

  print_list(head);
  printf("\n");
  
  printf("Inserting song 'Airplanes'...\n");
  head = insert_order(head, "Airplanes", "B.O.B");
  
  print_list(head);
  printf("\n");

  printf("Inserting song 'Galway Girl'...\n");
  head = insert_order(head, "Galway Girl", "Ed Sheeran");
  print_list(head);

  printf("Inserting song 'Chocolate'...\n");
  head = insert_order(head, "Chocolate", "Chocolate");
  print_list(head);

  printf("Inserting song 'Alpha'...\n");
  head = insert_order(head, "Alpha", "Alpha");
  print_list(head);

  printf("Inserting song 'Best'...\n");
  head = insert_order(head, "Best", "Best");
  print_list(head);
  
  printf("Inserting song 'Perfect'...\n");
  head = insert_order(head, "Perfect", "Ed Sheeran");
  print_list(head);
  
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
