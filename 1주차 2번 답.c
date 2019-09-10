#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int num;
	struct node *left;
	struct node *right;
}node;

void Nullnode(node *Setnode) {
	Setnode->left = NULL;
	Setnode->right = NULL;
}

void preorder(node *Rtree, int serch, int Lelem, int Relem) {

	if (Rtree->num != serch && Rtree->left != NULL || Rtree->right != NULL) {
		preorder(Rtree->left, serch, Lelem, Relem);
		preorder(Rtree->right, serch, Lelem, Relem);
	}
	else if(Rtree->num == serch){
		node *Lnode, *Rnode;
		Lnode = (node*)malloc(sizeof(node));
		Rnode = (node*)malloc(sizeof(node));

		Nullnode(Lnode);
		Nullnode(Rnode);

		if (Lelem != 0) Lnode->num = Lelem;
		if (Relem != 0) Rnode->num = Relem;

		Rtree->left = Lnode;
		Rtree->right = Rnode;

	}
}

int main() {
	int N, N2, elem1, elem2, elem3;
	char command[100];


	node *SerchTree;

	node *Dtree, *datanode1, *datanode2;
	Dtree = (node*)malloc(sizeof(node));
	datanode1 = (node*)malloc(sizeof(node));
	datanode2 = (node*)malloc(sizeof(node));

	Nullnode(Dtree);
	Nullnode(datanode1);
	Nullnode(datanode2);

	scanf("%d", &N);

	scanf("%d %d %d", &elem1, &elem2, &elem3);



	Dtree->num = elem1;
	datanode1->num = elem2;
	datanode2->num = elem3;


	Dtree->left = datanode1;
	Dtree->right = datanode2;


	for (int i = 0; i < N - 1; i++) {

		scanf("%d %d %d", &elem1, &elem2, &elem3);

		preorder(Dtree, elem1, elem2, elem3);
	}





	scanf("%d", &N2);

	for (int i = 0; i < N2; i++) {
		scanf("%s", command);
		SerchTree = Dtree;
		printf(" %d", SerchTree->num);

		for (int j = 0;; j++) {
			if (command[j] == NULL) break;
			else if (command[j] == 'R') {
				SerchTree = SerchTree->right;
				printf(" %d", SerchTree->num);
			}
			else if (command[j] == 'L') {
				SerchTree = SerchTree->left;
				printf(" %d", SerchTree->num);
			}
		}
		printf("\n");
	}


}