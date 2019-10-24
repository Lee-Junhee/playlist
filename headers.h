//structs
struct node {
	struct node *next;
	int data;
};


//functions
void print_list(struct node *head);

struct node * insert_front(struct node *head, int data);

struct node * free_list(struct node *head);
