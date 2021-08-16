#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	struct node* next;
}Node;


int Length(Node* head) {

	int count = 0;  // Initialize count
	Node* current = head;  // Initialize current

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

	head->data = 1; // assign data in first node
	head->next = second; // Link first node with second

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
	while (n != NULL) {
		printf(" %d ", n->data);
		n = n->next;
	}
}

void Append(Node** head1, Node** head2) {

	Node* temp1;
	temp1 = *head1;

	if (*head1 == NULL) {
		*head1 = *head2;
		*head2 = NULL;
		return;
	}

	while (temp1->next != NULL) {
		temp1 = temp1->next;
	}

	temp1->next = *head2;
	*head2 = NULL;
}

void deleteList(Node* start) {
	Node* p = start->next;
	if (p != 0) {
		deleteList(p);
	}
	printf("%d has been deleted!\n", start->data);
	free(start);
}


void frontBackSplit(Node* source, Node** frontRef, Node** backRef)
{
	int len = Length(source);
	if (len < 2)
	{
		*frontRef = source;
		*backRef = NULL;
		return;
	}

	 Node* current = source;

	int hopCount = (len - 1) / 2;        // (figured these with a few drawings)
	for (int i = 0; i < hopCount; i++) {
		current = current->next;
	}

	// Now cut at current
	*frontRef = source;
	*backRef = current->next;
	current->next = NULL;
}
int main()
{
	Node* head1 = NULL;
	int i;
	for (i = 27; i > 0; i--) {
		Push(&head1, i);
	}
	printf("Initial List: \n");
	printList(head1);
	printf("\nLenght: %d ", Length(head1));

	Node* a = NULL,*b = NULL;
	frontBackSplit(head1, &a, &b);
	printf("\n\nFront List: \n");
	printList(a);
	printf("\nLenght: %d ", Length(a));

	printf("\n\nBack List: \n");
	printList(b);
	printf("\nLenght: %d ", Length(b));
	
	printf("\n\n\n");
	deleteList(b);
	deleteList(a);
}