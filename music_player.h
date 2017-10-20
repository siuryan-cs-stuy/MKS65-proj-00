#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node * library[26];

// Get index of library based on artist name
int get_slot(char *);

// Add song
void add_song(char *, char *);

// Search for a song
struct node * search_song(char *, char *);

// Search for an artist
struct node * search_artist(char *);

// Print out all the entries under a certain letter
void print_letter(char);

// Print out all the songs of a certain artist
void print_artist(char *);

// Print out the entire library
void print_library();

// Print out a series of randomly chosen songs
void shuffle(int);

// Delete a song
void delete(char *, char*);

// Delete all the nodes
void delete_all();
