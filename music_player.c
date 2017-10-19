#include "linked_list.h"
#include "music_player.h"

// Add song
void add_song(char *song, char *artist) {
  char letter = tolower(song[0]);
  char a = 'a';
  library[letter-a] = insert_order(library[letter-a], song, artist);
}

// Search for a song
struct song_node * search_song(char *song) {

}

// Search for an artist
struct song_node * search_artist(char *artist) {

}

// Print out all the entries under a certain letter
void print_letter(char letter) {

}

// Print out all the songs of a certain artist
void print_artist(char *artist) {

}

// Print out the entire library
void print_library() {
  
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
