#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

int Length(Node*);
Node* BuildOneTwoThree();
void Push(Node**, int);
void printList(Node*);
void deleteList(Node*);
int GetNth(Node*, int );

int main()
{
	int num;
	Node* head = BuildOneTwoThree();

	Push(&head, 5);
	Push(&head, 2);
	Push(&head->next->next, 1);
	Push(&head, 5);
	Push(&head->next, 1);
	Push(&head->next, 4);
	Push(&head, 3);

	printf("Initial list: ");
	printList(head);

	printf("\n\nPosition of number you want to ckeck?  ");
	scanf(" %d", &num);

	printf("\n\In position %d is number %d! \n\n\n", num, GetNth(head, num));
}


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

int GetNth(Node* head, int n) {

	Node* current = head;
	int i;

	for (i = 0; i < n-1; i++) {
		current = current->next;
	}

	return current->data;
}