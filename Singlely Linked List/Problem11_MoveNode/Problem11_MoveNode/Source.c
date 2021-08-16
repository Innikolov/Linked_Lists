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
	if (p != 0) {
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



int main()
{
	Node* head;
	Node* head2 = NULL;

	head = BuildOneTwoThree();
	Push(&head, 2);
	Push(&head, 0);

	Push(&head2, 9);
	Push(&head2, 5);

	printf("Initial source list: \n");
	printList(head);

	printf("\n\nInitial destination list: \n");
	printList(head2);

	MoveNode(&head2, &head);
	MoveNode(&head2, &head);

	printf("\n\nSource after moving Node twice:  \n");
	printList(head);


	printf("\n\nDestination after moving Node twice:  \n");
	printList(head2);
	printf("\n\n");

	deleteList(head);
	deleteList(head2);
}
