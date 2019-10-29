#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"headers.h"

void print_list(struct song_node *head) {
	if (head != NULL) {
		printf("%s: %s | ", head->artist, head->name);
		print_list(head->next);
	}else {
		printf("\n");
	}
}

struct song_node * create_song(char *name, char *artist) {
	struct song_node *song = malloc(sizeof(struct song_node));
	strncpy(song->name, name, 100);
	strncpy(song->artist, artist, 100);
	song->next = NULL;
	return song;
}

struct song_node * insert_front(struct song_node *head,
		struct song_node *entry) {
	entry->next = head;
	return entry;
}

struct song_node * free_list(struct song_node *head) {
	if (head->next != NULL) {
		head->next = free_list(head->next);
	}
	free(head);
	return head->next;
}

struct song_node * insert_order(struct song_node *head,
		struct song_node *entry) {
	if (head == NULL) {
		return entry;
	}
	int cmp = strcmp(head->artist, entry->artist);
	if (cmp < 0) {
		head->next = insert_order(head->next, entry);
		return head;
	}
	if (cmp == 0) {
		cmp = strcmp(head->name, entry->name);
		if (cmp < 0) {
			entry->next = head->next;
			head->next = entry;
			return head;
		}else {
			entry->next = head;
			return entry;
		}
	}
	entry->next = head;
	return entry;
}

struct song_node * first_song(struct song_node *head,
		char *artist) {
	if (strcmp(head->artist, artist) == 0) {
		return head;
	}
	return first_song(head->next, artist);
}

struct song_node * rand_song(struct song_node *head) {
	struct song_node *song = head;
	return song;
}
