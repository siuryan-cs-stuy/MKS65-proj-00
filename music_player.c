#include "linked_list.h"
#include "music_player.h"
#include <ctype.h>

// Add song
void add_song(char *song, char *artist) {
  char letter = tolower(artist[0]);
  char a = 'a';
  library[letter-a] = insert_order(library[letter-a], song, artist);
}

// Search for a song
struct node * search_song(char *song) {

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

}

// Delete a song
void delete(char *song) {

}

// Delete all the nodes
void delete_all() {

}
