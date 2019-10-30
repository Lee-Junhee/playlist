#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"songlib.h"
#include"songnode.h"

struct song_node ** create_lib(){
	struct song_node **lib = calloc(sizeof(struct song_node *), 27);
	char alphabet[27] = "ZYXWVUTSRQPONMLKJIHGFEDCBA ";
	int i;
	char artist[10];
	for(i = 0; i < 27; i++) {
		strncpy(artist, &alphabet[26 - i], 1);
		lib[i] = create_song("", artist);
	}
	return lib;
}

void add_song(struct song_node **lib, struct song_node *entry){
	int i;
	struct song_node *head, *temp;
	struct song_node *next = entry->next;
	for(i = 26; i; i--) {
		head = lib[i];
		temp = insert_order(head, entry);
		if (head == temp) {
			break;
		}else {
			entry->next = next;
		}
	}
}

void add_songs(struct song_node **lib, struct song_node *head) {
	add_song(lib, head);
	struct song_node *temp = head->next;
	head->next = NULL;
	if (temp != NULL)	{
		add_songs(lib, temp);
	}
}

struct song_node * search_song(struct song_node **lib, char *title, char *artist){
	struct song_node *row = begins_with(lib, artist);
	return search(row, title, artist);
}

struct song_node * search_artist(struct song_node **lib, char *artist){
	struct song_node *row = begins_with(lib, artist);
	return first_song(row, artist);
}

struct song_node * begins_with(struct song_node **lib, char *letter){
	int i;
	for(i = 26; i; i--) {
		if (namecmp(lib[i]->artist, letter) <= 0) {
			break;
		}
	}
	return lib[i];
}

void print_artist(struct song_node **lib, char *artist){
	struct song_node *head = search_artist(lib, artist);
	while ((head != NULL) * !namecmp(head->artist, artist)) {
		print_song(head, 0);
		if (head-> next != NULL) {
			head = head->next;
		}else {
			break;
		}
	}
	printf("\n");
}

void print_lib(struct song_node **lib){
	int i;
	for(i = 0; i < 27; i++){
		if (lib[i]->next != NULL) {
			print_list(lib[i]);
		}
	}
}

void print_libv(struct song_node **lib){ //verbose
	int i;
	for(i = 0; i < 27; i++){
		print_list(lib[i]);
	}
}

struct song_node * shuffle(struct song_node **lib){
	int i;
	struct song_node *head = NULL;
	struct song_node *temp, *point;
	for(i = 0; i < 27; i++){
		if (lib[i]->next != NULL) {
			temp = lib[i]->next;
			if (head == NULL) {
				head = song_cpy(lib[i]->next);
				point = head;
				temp = temp->next;
			}
			while (temp != NULL) {
				point->next = song_cpy(temp);
				point = point->next;
				temp = temp->next;
			}

		}
	}
	temp = rand_song(head);
	struct song_node *random = song_cpy(temp);
	point = random;
	while (1) {
		head = song_pop(head, temp);
		if (head == NULL) {
			break;
		}
		temp = rand_song(head);
		random->next = song_cpy(temp);
		random = random->next;
	}
	return point;
}

void song_rm(struct song_node **lib, char *title, char *artist){
	struct song_node *row = begins_with(lib, artist);
	struct song_node *element = search_song(lib, title, artist);
	song_pop(row, element);
}

void clear_lib(struct song_node **lib){
	int i;
	for(i = 26; i; i--) {
		if (lib[i]->next != NULL) {
			lib[i]->next = free_list(lib[i]->next);
		}
	}	
}

void del_lib(struct song_node **lib) {
	int i;
	for(i = 0; i <27; i++) {
		free_list(lib[i]);
	}	
	free(lib);
}
