#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define COUNT 6

typedef struct tree {
	int data;
	struct tree* small;
	struct tree* big;
}Tree;


Tree* NewNode(int data) {

	Tree* newNode = (Tree*)malloc(sizeof(Tree));
	newNode->data = data;
	newNode->small = NULL;
	newNode->big = NULL;

	return newNode;
}

void Insert(Tree** rootRef, int data) {

	Tree* newTree = NewNode(data);

	if (*rootRef == NULL) {
		*rootRef == newTree;
		return;
	}
	else
	{
		if ((*rootRef)->data < newTree->data)
		{
			if ((*rootRef)->big == NULL)
			{
				(*rootRef)->big = newTree;
				return;
			}
			else
			{
				Insert(&(*rootRef)->big, data);
			}
		}
		else
		{
			if ((*rootRef)->small == NULL)
			{
				(*rootRef)->small = newTree;
				return;
			}
			else
			{
				Insert(&(*rootRef)->small, data);
			}
		}
	}
}

void printTree(Tree* root) {

	if (root == NULL) return;

	printTree(root->small);
	printTree(root->big);

	printf("%d \n", root->data);
}

void print2DUtil(Tree* root, int spaces)
{
	int i;

	if (root == NULL)
		return;


	spaces += COUNT;

	print2DUtil(root->big, spaces);

	printf("\n");

	for (i = COUNT; i < spaces; i++)
		printf(" ");


	printf("%d\n", root->data);

	print2DUtil(root->small, spaces);
}

// Wrapper over print2DUtil()
void print2D(Tree* root)
{
	// Pass initial space count as 0
	print2DUtil(root, 0);
}


int main() {

	Tree* root = NewNode(6);
	Insert(&root, 2);
	Insert(&root, 5);
	Insert(&root, 1);
	Insert(&root, 8);
	Insert(&root, 3);
	Insert(&root, 31);
	Insert(&root, 18);
	Insert(&root, 11);

	print2D(root);

	getchar();
}

