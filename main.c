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
  print_list(head);


  printf("==============================\n");
  printf("TESTING MUSIC PLAYER FUNCTIONS\n");
  printf("==============================\n");
  printf("\n");

  //fill up library as well as test add_song & print_library
  printf("Creating music collection...\n");
  printf("Adding 'Around The World'...\n");
  add_song("Around The World", "Daft Punk");
  printf("Adding 'Shape of You'...\n");
  add_song("Shape of You", "Ed Sheeran");
  print_library();
  printf("\n");
  
  printf("Adding 'Chocolate'...\n");
  add_song("Chocolate", "Chocolate");
  printf("Adding 'Alpha'...\n");
  add_song("Alpha", "Alpha");
  printf("Adding 'Galway Girl'...\n");
  add_song("Galway Girl", "Ed Sheeran");
  printf("Adding 'Best'...\n");
  add_song("Best", "Best");
  printf("Adding 'Around The World'...\n");
  add_song("Around The World", "Red Hot Chili Peppers");
  printf("Adding 'Airplanes'...\n");
  add_song("Airplanes", "B.O.B");
  printf("Adding 'Bailando'...\n");
  add_song("Bailando", "Enrique Iglesias");
  print_library();
  printf("\n");

  //search_artist
  printf("Searching song by 'Best'...\n");
  print_list(search_artist("Best"));
  printf("Searching song by 'Ed Sheeran'...\n");
  print_list(search_artist("Ed Sheeran"));
  printf("Searching song by 'Alpha'...\n");
  print_list(search_artist("Alpha"));
  printf("Searching song by 'Taylor Swift'...\n");
  print_list(search_artist("Taylor Swift"));
  printf("\n");

  //printing each letter:
  char c;
  for(c = 'A'; c <= 'Z'; ++c){
    printf("Letter %c: ", c);
    print_letter(c);
  }
  printf("\n");

  //print only songs by artist
  printf("Searching for all songs by 'Ed Sheeran'...\n");
  print_artist("Ed Sheeran");
  printf("Searching for all songs by 'Best'...\n");
  print_artist("Best");
  printf("Searching for all songs by 'Taylor Swift'...\n");
  print_artist("Taylor Swift");
  printf("\n");
  
  printf("Finding song 'Shape of You' by Ed Sheeran...\n");
  print_list(search_song("Shape of You", "Ed Sheeran"));
  
  printf("Finding song 'DNE' by abc...\n");
  print_list(search_song("DNE", "abc"));
  printf("\n");

  printf("Shuffling...\n");
  shuffle(10);
  printf("\n");
  
  printf("Removing song 'Shape of You' by Ed Sheeran...\n");
  delete("Shape of You", "Ed Sheeran");
  print_letter('E');
  
  printf("Removing song 'DNE' by abc...\n");
  delete("DNE", "abc");
  print_library();
  printf("\n");

  printf("Deleting all songs...\n");
  delete_all();
  printf("\n");
  
  return 0;
}
