#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


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

void addTree(Tree** root, int data) {

	Tree* newTree = NewNode(data);

	if ((*root)->data >= newTree->data) {
		(*root)->small = newTree;
	}
	else {
		(*root)->big = newTree;
	}

}

void printTree(Tree* root) {

	if (root == NULL) return;

	printTree(root->small);
	printTree(root->big);

	printf("%d \n", root->data);
}


int main() {

	Tree* root = NewNode(4);
	addTree(&root, 2);
	addTree(&root, 5);
	addTree(&root->small, 1);
	addTree(&root->small, 3);

	printTree(root);
}

