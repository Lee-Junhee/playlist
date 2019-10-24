#include<stdio.h>
#include<stdlib.h>
#include"headers.h"

void print_list(struct node *head){
	printf("[ ");
	while (head->next != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("]\n");
}

struct node * insert_front(struct node *head, int data) {
	struct node *new_head = malloc(sizeof(struct node));
	new_head->next = head;
	new_head->data = data;
	return new_head;
}

struct node * free_list(struct node *entry){
	//printf("DIAG: freeing node %d...\n", entry->data);
	if (entry->next != NULL) {
		entry->next = free_list(entry->next);
	}
	free(entry);
	//printf("DIAG: freed node %d\n", entry->data);
	return entry->next;

}
