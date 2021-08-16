#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

int Length(Node*);
Node* BuildOneTwoThree();
void Push(Node** , int );
void printList(Node* );
void deleteList(Node* );
int Count(Node**, int);

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

	printf("\n\nWhat number from 1 to 5 do you want to know the count of?  ");
	scanf(" %d", &num);

	printf("\n\Number %d occurs %d times! \n\n\n", num, Count(&head, num));

	deleteList(head);
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

int Count(Node** head, int num) {

	int count = 0;  // Initialize count
	Node* current = *head;  // Initialize current

	while (current != NULL)
	{
		if(current->data == num) count++;	
		current = current->next;
	}
	return count;
}