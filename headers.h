//structs
struct song_node {
	char name[100];
	char artist[100];
	struct song_node *next;
};

//functions
struct song_node * create_song(char *name, char *artist);

void print_list(struct song_node *head);

struct song_node * insert_front(struct song_node *head,
		struct song_node *entry);

struct song_node * free_list(struct song_node *head);

struct song_node * insert_order(struct song_node *head,
		struct song_node *entry);

struct song_node * first_song(struct song_node *head,
		char *artist);

struct song_node * rand_song(struct song_node *head);
