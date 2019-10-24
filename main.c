#include<stdio.h>
#include<stdlib.h>
#include"headers.h"

int main() {
	struct node *list = calloc(sizeof(struct node), 1);
	printf("Printing empty list:\n");
	print_list(list);
	int i;
	printf("Adding #s 0-9 to list...\n");
	for(i = 0; i <= 9; i++){
		list = insert_front(list, i);
	}
	printf("Printing list:\n");
	print_list(list);
	printf("Freeing list...\n");
	free_list(list);
	printf("Printing from reference to old list...\n");
	print_list(list);

	return 0;
}
