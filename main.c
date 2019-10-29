#include<stdio.h>
#include<stdlib.h>
#include"headers.h"

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
	print_list(songs);

	return 0;
}
