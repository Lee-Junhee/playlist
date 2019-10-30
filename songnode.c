#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"songnode.h"

void print_song(struct song_node *song, char newline) {
	char line[2];
	if (newline) {
		strcpy(line, "\n");
	}else {
		strcpy(line, "");
	}
	printf("%s: %s | %s", song->artist, song->name, line);
}

void print_list(struct song_node *head) {
	if (head != NULL) {
		print_song(head, 0);
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

int namecmp(char *str1, char *str2) {//case-insensitive strcmp
	int char1, char2;
	char1 = tolower(*str1++);
	char2 = tolower(*str2++);
	if ((char1 == char2) * (char1 != NULL)) {
		return namecmp(str1, str2);
	}
	return char1 - char2;
}

struct song_node * insert_order(struct song_node *head,
		struct song_node *entry) {
	if (head == NULL) {
		return entry;
	}
	int cmp = namecmp(head->artist, entry->artist);
	if (cmp < 0) {
		head->next = insert_order(head->next, entry);
		return head;
	}
	if (cmp == 0) {
		cmp = namecmp(head->name, entry->name);
		if (cmp < 0) {
			head->next = insert_order(head->next, entry);
			return head;
		}else {
			entry->next = head;
			return entry;
		}
	}
	entry->next = head;
	return entry;
}

struct song_node * search(struct song_node *head,
		char *title, char *artist) {
	struct song_node *start = first_song(head, artist);
	while (!namecmp(start->artist, artist)) {
		if (namecmp(start->name, title)) {
			start = start->next;
		}else {
			return start;
		}
	}
	return NULL;
}

struct song_node * first_song(struct song_node *head,
		char *artist) {
	if (namecmp(head->artist, artist) == 0) {
		return head;
	}
	return first_song(head->next, artist);
}

struct song_node * rand_song(struct song_node *head) {
	struct song_node *song = head;
	srand(time(NULL));
	int length = 1;
	while (song->next != NULL) {
		length++;
		song = song->next;
	}
	song = head;
	int random = rand() % length;
	while (random) {
		if (song->next != NULL) {
			song = song->next;
		}else {
			song = head;
		}
		random --;
	}
	return song;
}

struct song_node * song_pop(struct song_node *head, struct song_node *song) {
	if (head == song) {
		return head->next;
	}
	head->next = song_pop(head->next, song);
	return head;
}
