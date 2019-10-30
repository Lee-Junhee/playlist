//structs
struct song_node {
	char name[100];
	char artist[100];
	struct song_node *next;
};

//functions
struct song_node * create_song(char *name, char *artist);

struct song_node * song_cpy(struct song_node *src);

void print_song(struct song_node *song, char newline);

void print_list(struct song_node *head);

struct song_node * insert_front(struct song_node *head,
		struct song_node *entry);

struct song_node * free_list(struct song_node *head);

int namecmp(char *str1, char *str2);

struct song_node * insert_order(struct song_node *head,
		struct song_node *entry);

struct song_node * search(struct song_node *head,
		char *title, char *artist);

struct song_node * first_song(struct song_node *head,
		char *artist);

struct song_node * rand_song(struct song_node *head);

struct song_node * song_pop(struct song_node *head, struct song_node *song);
