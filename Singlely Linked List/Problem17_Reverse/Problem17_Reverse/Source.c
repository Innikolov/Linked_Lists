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

Node* NewNode(int data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));

	/* put in the data  */
	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

void Push_Tail(Node** headRef, int newData) {

	Node* current = *headRef;
	Node* newNode = NewNode(newData);
	if (current == NULL) {
		*headRef = newNode;
	}
	else
	{
		while (current->next != NULL) {
			current = current->next;
		}

		current->next = newNode;
	}
}

void MoveNode(Node** dest, Node** src) {

	Node* moved_node = *src;
	*src = moved_node->next;
	moved_node->next = *dest;
	*dest = moved_node;
}

void Reverse(Node** head) {

	Node* current, *prev, *next;
	current = *head;
	prev = NULL;
	
	while (current != NULL) {
		
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;

	}
	*head = prev;
}
int main()
{
	Node* head = NULL;

	Push(&head, 19);
	Push(&head, 15);
	Push(&head, 8);
	Push(&head, 5);
	Push(&head, 5);
	Push(&head, 1);



	printf("List: \n");
	printList(head);

	Reverse(&head);

	printf("\n\nReversed List: \n");
	printList(head);


	printf("\n\n  \n");
	deleteList(head);

}
