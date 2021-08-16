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
void Insert_into_sorted(Node**, Node*);
Node* newNode(int new_data);
void Sort(Node**);


int main()
{
	Node* head;
	head = BuildOneTwoThree();

	printf("Initial list: ");
	printList(head);

	Push(&head, 5);
	Push(&head, 2);
	Push(&head, 9);
	Push(&head, 0);
	printf("\n\List after pushing a few extra elements:  \n");
	printList(head);
	printf("\n\n");


	Sort(&head);
	printf("\n\nSorted list with added node:  \n");
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

 Node* newNode(int data)
{
	 Node* new_node	= ( Node*) malloc(sizeof( Node));

	/* put in the data  */
	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

 void Sort(Node** head_ref) {

	 Node* sorted;
	 sorted = NULL;

	 Node* current = *head_ref;

	 while (current != NULL) {

		 Node* next;
		 next = current->next;

		 Insert_into_sorted(&sorted, current);

		 current = next;
	 }
	 *head_ref = sorted;
 }

 void Insert_into_sorted(Node** sorted_ref, Node* new_node)
 {
	 Node* current;

	 if (*sorted_ref == NULL || (*sorted_ref)->data >= new_node->data)
	 {
		 new_node->next = *sorted_ref;
		 *sorted_ref = new_node;
	 }
	 else
	 {
		 current = *sorted_ref;

		 while (current->next != NULL && current->next->data < new_node->data)
		 {
			 current = current->next;
		 }

		 new_node->next = current->next;
		 current->next = new_node;
	 }
 }