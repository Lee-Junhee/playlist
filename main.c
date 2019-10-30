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
	struct song_node *rm = create_song("Can't Hold Us",
			"Macklemore & Ryan Lewis");
	songs = insert_order(songs,
			rm);
	songs = insert_order(songs,
			create_song("uptown funk",
				"bruno mars"));

	printf("\n===============\n");
	printf("Song Node Functions\n");

	printf("\n===============\n");
	printf("Testing print_list()...\n");
	print_list(songs);

	printf("\n===============\n");
	printf("Testing random_song()...\n");
	print_song(rand_song(songs), 1);

	printf("\n===============\n");
	printf("Testing first_song('Bruno Mars')...\n");
	print_song(first_song(songs, "Bruno Mars"), 1);

	printf("\n===============\n");
	printf("Testing insert_front()\n");
	songs = insert_front(songs, create_song("On Top of the World",
				"Imagine Dragons"));
	print_list(songs);

	printf("\n===============\n");
	printf("Testing search(songs, 'marry you', 'bruno mars')...\n");
	struct song_node *result = search(songs, "marry you", "bruno mars");
	printf("%p\n", result);
	print_song(result, 1);

	printf("\n===============\n");
	printf("Testing song_pop()...(removing 'Can't Hold Us')\n");
	song_pop(songs, rm);
	print_list(songs);

	printf("\n===============\n");
	printf("Freeing list...\n");
	songs = free_list(songs);
	printf("Freed list! Remaining songs:\n");
	print_list(songs);

	printf("\n===============\n");

	printf("Song Library Functions\n");
	printf("\n===============\n");
	printf("Creating library...\n");
	struct song_node **lib = create_lib();
	printf("Adding songs...\n");
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
	printf("Printing Library...\n");
	print_lib(lib);

	printf("\n===============\n");
	printf("Testing print_artist('bruno mars')...\n");
	print_artist(lib, "bruno mars");

	printf("\n===============\n");
	printf("Testing begins_with('f')...\n");
	print_list(begins_with(lib, "f"));

	printf("\n===============\n");
	printf("Testing search_song('legend', 'the score')...\n");
	result = search_song(lib, "legend", "the score");
	printf("%p\n", result);
	print_song(result, 1);

	printf("\n===============\n");
	printf("Testing search_artist('fitz and the tantrums')...\n");
	print_list(search_artist(lib, "fitz and the tantrums"));

	printf("\n===============\n");
	printf("Testing shuffle()...\n");
	struct song_node *rand = shuffle(lib);
	print_list(rand);

	printf("\n===============\n");
	printf("Testing song_rm('can't hold us', 'macklemore & ryan lewis')...\n");
	song_rm(lib, "can't hold us", "macklemore & ryan lewis");
	print_lib(lib);

	printf("\n===============\n");
	printf("Testing clear_lib()...\n");
	clear_lib(lib);
	print_libv(lib);

	printf("\n===============\n");
	printf("Testing del_lib()...\n");
	del_lib(lib);
	lib = NULL;
	printf("Remaining library:\n");
	print_list(lib);

	return 0;
}
