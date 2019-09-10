#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodetype {
	char data;
	struct nodetype *pre_node;
	struct nodetype *next_node;
}node;

typedef struct listtype {
	int count;
	node headnode;
	node trailnode;
}list;

list *makelist() {
	list *returnlist;
	returnlist = (list *)malloc(sizeof(list));

	memset(returnlist, NULL, sizeof(list));
	returnlist->headnode.next_node = &returnlist->trailnode;
	returnlist->trailnode.pre_node = &returnlist->headnode;
	returnlist->count = 0;

	return returnlist;
}

void add(list *Plist, int p, node d) {
	if (p < 1 || p > Plist->count + 1) {
		printf("invalid position\n");
		return;
	}
	else {
		int i;
		node *temp = &Plist->headnode;

		for (i = 0; i < p; i++) {
			temp = temp->next_node;
		}

		node *newnode = (node *)malloc(sizeof(node));
		*newnode = d;
		newnode->pre_node = temp->pre_node;
		newnode->next_node = temp;
		temp->pre_node->next_node = newnode;
		temp->pre_node = newnode;

		Plist->count++;

		return;
	}
}

void delete(list *Plist, int p) {
	if (p < 1 || p > Plist->count) {
		printf("invalid position\n");
		return;
	}
	else {
		int i;
		node *temp = &Plist->headnode;

		for (i = 0; i < p; i++) {
			temp = temp->next_node;
		}

		temp->pre_node->next_node = temp->next_node;
		temp->next_node->pre_node = temp->pre_node;

		Plist->count--;
		return;
	}
}

void get(list *Plist, int p) {
	if (p < 1 || p > Plist->count) {
		printf("invalid position\n");
	}
	else {
		int i;
		node *temp = &Plist->headnode;
		for (i = 0; i < p; i++) {
			temp = temp->next_node;
		}
		printf("%c\n", temp->data);
		return;
	}
}

void print(list *Plist) {
	node *temp = &Plist->headnode;

	for (int i = 0; i < Plist->count; i++) {
		temp = temp->next_node;
		printf("%c", temp->data);
	}
	temp = &Plist->headnode;

	printf("\n");
	return;
}

int main() {
	list *DL;
	DL = makelist();

	int r, n, i;
	char list;
	node datanode;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		getchar();
		scanf("%c", &list);

		if (list == 'A') {
			scanf("%d %c", &r, &datanode.data);
			add(DL, r, datanode);
		}

		else if (list == 'D') {
			scanf("%d", &r);
			delete(DL, r);
		}

		else if (list == 'G') {
			scanf("%d", &r);
			get(DL, r);
		}

		else if (list == 'P') {
			print(DL);
		}
	}

	return 0;
}