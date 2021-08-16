#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	struct node* next;
}Node;

int Length(Node* headRef) {

	int count = 0;  // Initialize count
	Node* current = headRef;  // Initialize current

	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

Node* BuildOneTwoThree() {

	Node* head = (Node*)malloc(sizeof(Node));
	Node* second = (Node*)malloc(sizeof(Node));
	Node* third = (Node*)malloc(sizeof(Node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	return head;
}

void Push(Node** headRef, int newData) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->next = *headRef;

	*headRef = newNode;
}

void printList(Node* n)
{
	if (n == NULL) return;
	printf(" %d ", n->data);
	printList(n->next);
}

void deleteList(Node* start) {
	Node* p = start->next;
	if (p != NULL) {
		deleteList(p);
	}
	printf("%d has been deleted!\n", start->data);
	free(start);
}

Node* newNode(int data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));

	/* put in the data  */
	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

void MoveNode(Node** dest, Node** src) {

	Node* moved_node = *src;
	*src = moved_node->next;
	moved_node->next = *dest;
	*dest = moved_node;
}

void AlternatingSplit(Node* source, Node** aRef, Node** bRef)
{
	Node* now = source;
	Node* a = *aRef;
	Node* b = *bRef;

	while (now != NULL)
	{
		MoveNode(&a, &now);

		if (now != NULL)
		{
			MoveNode(&b, &now);
		}
	}

	*aRef = a;
	*bRef = b;

}

int main()
{
	Node* head = NULL;
	Node* a = NULL;
	Node* b = NULL;

	head = BuildOneTwoThree();
	Push(&head, 2);
	Push(&head, 1);
	Push(&head, 9);
	Push(&head, 5);

	printf("Initial source list: \n");
	printList(head);

	AlternatingSplit(head, &a, &b);

	printf("\n\nList A:  \n");
	printList(a);

	printf("\n\nList B:  \n");
	printList(b);
	printf("\n\n");

	deleteList(a);
	deleteList(b);

}
