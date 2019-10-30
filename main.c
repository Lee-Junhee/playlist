#include<stdio.h>
#include<stdlib.h>
#include"songnode.h"
#include"songlib.h"

int main() {
	struct song_node *songs;
	songs = create_song("Just the Way You Are", 
			"Bruno Mars");
	songs = insert_order(songs,
			create_song("Marry You",
				"Bruno Mars"));
	songs = insert_order(songs,
			create_song("VIP",
				"Manic Drive"));
	songs = insert_order(songs,
			create_song("HandClap",
				"Fitz and the Tantrums"));
	songs = insert_order(songs,
			create_song("Roll Up",
				"Fitz and the Tantrums"));
	songs = insert_order(songs,
			create_song("Legend",
				"The Score"));
	songs = insert_order(songs,
			create_song("Can't Hold Us",
				"Macklemore & Ryan Lewis"));
	songs = insert_order(songs,
			create_song("uptown funk",
				"bruno mars"));

	printf("\n===============\n");
	printf("Song Node Functions\n");

	printf("\n===============\n");
	printf("Testing print_list(songs)...\n");
	print_list(songs);

	printf("\n===============\n");
	printf("Testing random_song(songs)...\n");
	print_song(rand_song(songs), 1);

	printf("\n===============\n");
	printf("Testing first_song(songs, 'Bruno Mars')...\n");
	print_song(first_song(songs, "Bruno Mars"), 1);

	printf("\n===============\n");
	printf("Testing insert_front()\n");
	songs = insert_front(songs, create_song("On Top of the World",
				"Imagine Dragons"));
	print_list(songs);

	printf("\n===============\n");
	printf("Freeing list...\n");
	songs = free_list(songs);
	printf("Freed list! New songs:\n");
	print_list(songs);

	printf("\n===============\n");

	printf("Song Library Functions\n");
	printf("\n===============\n");
	struct song_node **lib = create_lib();
	printf("Printing Library...\n");
	print_lib(lib);

	printf("\n===============\n");
	printf("Adding songs to library...\n");
	add_song(lib, create_song("uPtown fuNk", "bRuno marS"));
	add_song(lib, create_song("Just the Way You Are", "bruno Mars"));
	add_song(lib, create_song("Marry You", "Bruno Mars"));
	//create a linked list of songs
	songs = insert_order(songs,
			create_song("VIP",
				"Manic Drive"));
	songs = insert_order(songs,
			create_song("HandClap",
				"Fitz and the Tantrums"));
	songs = insert_order(songs,
			create_song("Roll Up",
				"Fitz and the Tantrums"));
	songs = insert_order(songs,
			create_song("Legend",
				"The Score"));
	songs = insert_order(songs,
			create_song("Can't Hold Us",
				"Macklemore & Ryan Lewis"));
	//use a function to add linked list into the library
	add_songs(lib, songs);
	print_lib(lib);

	return 0;
}
