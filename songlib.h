struct song_node ** create_lib();

void add_song(struct song_node **lib, struct song_node *entry);

void add_songs(struct song_node **lib, struct song_node *head);

struct song_node * search_song(struct song_node **lib, char *title, char *artist);

struct song_node * search_artist(struct song_node **lib, char *artist);

struct song_node * begins_with(struct song_node **lib, char *letter);

void print_artist(struct song_node **lib, char *artist);

void print_lib(struct song_node **lib);

struct song_node * shuffle(struct song_node **lib);

void song_rm(struct song_node **lib, char *title, char *artist);

void clear_lib(struct song_node **lib);

void del_lib(struct song_node **lib);
