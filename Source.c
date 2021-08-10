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
void Insert(Node** , int , int );


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

	Insert(&head, 10, 4);
	printf("\n\nList after insert(10,4):  \n");
	printList(head);
	printf("\n\n");
	Insert(&head, 8, 15);
	printf("\n\List after insert(8,6):  \n");
	printList(head);
	printf("\n\n");

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

void Insert(Node** head_ref, int data, int n)
{
	if (n < 1 || n > Length(*head_ref)) {
		printf("\n-------------INVALID INDEX!--------------\n");
		return;
	}

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;

	// If we want to insert to first position (begining of list) change the head to point to the new node.
	if (n == 1) {
		new_node->next = *head_ref;
		*head_ref = new_node;
		return;
	}


	Node* temp = (Node*)malloc(sizeof(Node));
	temp = *head_ref;
	int i = 0;

	// Traverse till the n-th node.
	while (i++ < n - 2)
		temp = temp->next;

	// Change the next of n-th node and the temp. 
	new_node->next = temp->next;
	temp->next = new_node;
}