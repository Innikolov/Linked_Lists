#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define COUNT 3

typedef struct node {
	int data;
	struct node* small;
	struct node* big;
}Node;


Node* NewNode(int data) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->small = NULL;
	newNode->big = NULL;

	return newNode;
}

void Insert(Node** rootRef, int data) {

	Node* newTree = NewNode(data);

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

void printTree(Node* root) {

	if (root == NULL) return;

	printTree(root->small);
	printTree(root->big);

	printf("%d \n", root->data);
}

void print2DUtil(Node* root, int spaces)
{
	int i;

	if (root == NULL)
		return;


	spaces += COUNT;

	print2DUtil(root->big, spaces);

	printf("\n");

	for (i = COUNT; i < spaces; i++)
		printf("  ");


	printf("%d\n", root->data);

	print2DUtil(root->small, spaces);
}

// Wrapper over print2DUtil()
void print2D(Node* root)
{
	// Pass initial space count as 0
	print2DUtil(root, 0);
}

static Node* Append(Node* a, Node* b) {
	Node* A, * B;
	
	if (a == NULL) return b;
	if (b == NULL) return a;

	A = a->small; // null
	B = b->small; // 1

	A->big = b; // 1 - 5
	b->small = A; // null - 1

	B->big = a;  // 1 - 1
	a->small = B; // null - 5

	return a;
}

static Node* treeToList(Node** root) {

	Node* ListA, * ListB;

	if ((*root) == NULL) return NULL;

	
	ListA = treeToList(&(*root)->small);
	ListB = treeToList(&(*root)->big);

	(*root)->big = *root;
	(*root)->small = *root;

	ListA = Append(ListA, *root);
	ListA = Append(ListA, ListB);

	return ListA;
}

void printList(Node* root) {
	Node* current = root;

	while (current != NULL) {
		printf("%d ", current->data);
		current = current->big;
		if (current == root) break;
	}
	printf("\n");
}

int main() {

	Node* root = NewNode(20);
	Insert(&root, 10);
	Insert(&root, 30);
	Insert(&root, 5);
	Insert(&root, 1);
	Insert(&root, 15);
	Insert(&root, 25);
	Insert(&root, 6);
	Insert(&root, 33);
	Insert(&root, 12);
	Insert(&root, 17);
	Insert(&root, 32);
	Insert(&root, 35);
	Insert(&root, 36);

	print2D(root);
	printf("\n\n");

	Node* newList = treeToList(&root);


	printList(newList);

	getchar();
}

