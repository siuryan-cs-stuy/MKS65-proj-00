#include <ctype.h>

#include "linked_list.h"
#include "music_player.h"

int get_slot(char *artist) {
  return tolower(artist[0]) - 'a';
}

// Add song
void add_song(char *song, char *artist) {
  int slot = get_slot(artist);
  library[slot] = insert_order(library[slot], song, artist);
}

// Search for a song
struct node * search_song(char *song, char *artist) {
  int slot = get_slot(artist);
  struct node *temp = find_song(library[slot], song);
  return temp;
}

// Search for an artist
struct node * search_artist(char *artist) {
  char letter = tolower(artist[0]);
  char a = 'a';
  struct node *temp = library[letter-a];
  temp = find_artist(temp, artist);
  if(temp == 0){
    printf("Artist not found.\n");
    return 0;
  }
  printf("Artist found!\n");
  return temp;
}

// Print out all the entries under a certain letter
void print_letter(char letter) {
  char index = tolower(letter);
  char a = 'a';
  print_list(library[index-a]);
}

// Print out all the songs of a certain artist
void print_artist(char *artist) {
  struct node *temp = search_artist(artist);
  printf("[");
  while(find_artist(temp, artist) != 0){
    printf("%s by %s, ", temp->name, temp->artist);
    temp = temp->next;
  }
  printf("]\n");
}

// Print out the entire library
void print_library() {
  printf("[");
  int i = 0;
  for(i = 0; i < 26; i++){
    //printf("LIB: %d\n", i);
    print_listh(library[i]);
  }
  printf("]\n");
}

// Print out a series of randomly chosen songs
void shuffle(int num) {
  int rand_letter = rand() % 26;
  printf("[");
  while (num > 0) {
    struct node *temp = random_node(library[rand_letter]);
    if (temp) {
      printf("%s by %s,", temp->name, temp->artist);
      num--;
    }
    rand_letter = rand() % 26;
  }
  printf("]");
}

// Delete a song
void delete(char *song, char *artist) {
  int slot = get_slot(artist);
  struct node *temp = search_song(song, artist);
  if (temp) {
    library[slot] = remove_node(library[slot], temp);
  }
}

// Delete all the nodes
void delete_all() {
  int i;
  for (i = 0; i < 26; i++) {
    library[i] = free_list(library[i]); 
  }
}
