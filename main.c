#include "linked_list.h"
#include "music_player.h"

int main() {
  srand(time(NULL));
  
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
  head->next = 0;
  print_list(head);
  printf("\n");

  printf("Inserting song 'Alpha' in front...\n");
  head = insert_front(head, "Alpha", "Alpha");
  print_list(head);
  printf("\n");
  
  printf("Inserting song 'Galway Girl'...\n");
  head = insert_order(head, "Galway Girl", "Ed Sheeran");

  printf("Inserting song 'Zoo'...\n");
  head = insert_order(head, "Zoo", "Zoo");

  printf("Inserting song 'Chocolate'...\n");
  head = insert_order(head, "Chocolate", "Chocolate");

  printf("Inserting song 'Best'...\n");
  head = insert_order(head, "Best", "Best");
  
  printf("Inserting song 'Perfect'...\n");
  head = insert_order(head, "Perfect", "Ed Sheeran");
  print_list(head);
  printf("\n");
  
  printf("Finding song 'Galway Girl'...\n");
  print_list(find_song(head, "Galway Girl"));
  
  printf("Finding song 'DNE'...\n");
  print_list(find_song(head, "DNE"));
  printf("\n");
  
  printf("Finding artist 'Ed Sheeran'...\n");
  print_list(find_artist(head, "Ed Sheeran"));
  printf("\n");

  printf("Getting random song\n");
  struct node *song = random_node(head);
  printf("%s by %s\n", song->name, song->artist);
  
  printf("Getting random song\n");
  song = random_node(head);
  printf("%s by %s\n", song->name, song->artist);
  printf("\n");

  printf("Removing song 'Galway Girl'...\n");
  head = remove_node(head, find_song(head, "Galway Girl"));
  print_list(head);
  printf("\n");

  printf("Freeing memory from head pointer...\n");
  head = free_list(head);
  

  printf("=============================\n");
  printf("TESTING LINKED LIST FUNCTIONS\n");
  printf("=============================\n");
  printf("\n");

  printf("Creating music collection...\n");
  printf("Adding 'Shape of You'...\n");
  add_song("Shape of You", "Ed Sheeran");
  //print_library();
  printf("\n");
  
  printf("Freeing memory from head pointer...\n");
  head = free_list(head);
  
  return 0;
}
