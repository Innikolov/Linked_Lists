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

int main() 
{
	Node* head1 = BuildOneTwoThree();
	Node* head2 = NULL;

	Push(&head2, 6);
	Push(&head2, 5);
	Push(&head2, 4);
	printf("List A: \n");
	printList(head1);
	printf("\n\nList B: \n");
	printList(head2);

	Append(&head1, &head2);
	printf("\n\nList A after Append: \n");
	printList(head1);

	Append(&head2, &head1); 
	printf("\n\nList B (NULL) after Appending with A: \n");
	printList(head2);

	printf("\n\n\n");
	deleteList(head2);
}