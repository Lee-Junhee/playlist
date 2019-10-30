#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"songlib.h"
#include"songnode.h"

struct song_node ** create_lib(){
	struct song_node **lib = calloc(sizeof(struct song_node *), 27);
	char alphabet[27] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	int i;
	char artist[10];
	for(i = 0; i < 27; i++) {
		strncpy(artist, &alphabet[26 - i], 1);
		lib[i] = create_song("", artist);
	}
	return lib;
}

void add_song(struct song_node entry){
}

struct song_node * search_song(char *title, char *artist){
}

struct song_node * search_artist(char *artist){
}

struct song_node * begins_with(char *letter){
}

void print_artist(char *artist){
}

void print_lib(struct song_node **lib){
	int i;
	for(i = 0; i < 27; i++){
		print_list(lib[i]);
	}
}


struct song_node * shuffle(struct song_node **lib){
}

struct song_node * song_rm(struct song_node **lib, char *title, char *artist){
}

void clear_lib(struct song_node **lib){
}
