#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

 
int Length(Node*);
Node* BuildOneTwoThree();
void AddToTail(Node** head_ref, int data);
void Push(Node** headRef, int newData);
void ChangeToNull(Node** headRef);
void Insert(int data, int n, Node** head_ref);
void printList(Node* n);
void deleteList(Node* start);
void delete(Node** head_ref, int n);
void reverseList(Node** head_ref);


int main() {

	//Pointer to first node;
	Node* head = BuildOneTwoThree();
	printf("Initial List: ");
	printList(head);
	printf("\nLenght is: %d\n\n", Length(head));

	Push(&head, 13);
	printf("After pushing 13 at head: ");
	printList(head);
	printf("\nLenght is: %d\n\n", Length(head));

	AddToTail(&head, 101);
	printf("After adding 101 to tail end: ");
	printList(head);
	printf("\nLenght is: %d\n\n", Length(head));

	delete(&head, 3);
	printf("After deleting 3rd element: ");
	printList(head);
	printf("\nLenght is: %d\n\n", Length(head));

	reverseList(&head);
	printf("After reversing List: ");
	printList(head);
	printf("\nLenght is: %d\n\n", Length(head));

	ChangeToNull(&head->next->next);
	printf("After changing head+2 to NULL : ");
	printList(head);
	printf("\nLenght is: %d\n\n", Length(head));

	Insert(55, 2, &head);
	printf("After Inserting 55 at position 2: ");
	printList(head);
	printf("\nLenght is: %d\n\n", Length(head));


	deleteList(head);
}

void AddToTail(Node** head_ref, int data) {
	Node* tail = (Node*)malloc(sizeof(Node));
	Node* temp = *head_ref;
	tail->data = data;
	tail->next = NULL;

	if (*head_ref == NULL)
	{
		*head_ref = tail;
		return;
	}

	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = tail;
	return;
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

void ChangeToNull(Node** headRef)
{
	*headRef = NULL;
}

void Insert(int data, int n, Node** head_ref)
{
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

void delete(Node** head_ref, int n) {

	int i;
	Node* temp = *head_ref;

	//If we want to delete first element, just set the head to point to second element and delete the first.
	if (n == 1) {
		*head_ref = temp->next;
		free(temp);
		return;
	}

	//Traverse to n-1 position.
	for (i = 0; i < n - 2; i++) {
		temp = temp->next;
	}

	//Set temp2 to be the nth element, and fix the links.
	Node* temp2 = temp->next;
	temp->next = temp2->next;

	//Delete the element.
	free(temp2);
}

void reverseList(Node** head_ref) {

	Node* current = *head_ref;
	Node* prev = NULL;
	Node* next = current->next;

	while(current != NULL) {
		next = current->next;
		current->next = prev;		
		prev = current;	
		current = next;
	}

	*head_ref = prev;
}

