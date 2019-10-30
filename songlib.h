struct song_node ** create_lib();

void add_song(struct song_node entry);

struct song_node * search_song(char *title, char *artist);

struct song_node * search_artist(char *artist);

struct song_node * begins_with(char *letter);

void print_artist(char *artist);

void print_lib(struct song_node **lib);

struct song_node * shuffle(struct song_node **lib);

struct song_node * song_rm(struct song_node **lib, char *title, char *artist);

void clear_lib(struct song_node **lib);
