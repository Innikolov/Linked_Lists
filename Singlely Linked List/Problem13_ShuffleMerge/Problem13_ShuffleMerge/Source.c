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

void MoveToEndNode(Node** dest, Node** src) {

	Node* moved_node = *src;
	*src = moved_node->next;
	Node* dest_tail = *dest;

	while (dest_tail->next != NULL) {
		dest_tail = dest_tail->next;
	}

	dest_tail->next = moved_node;
	moved_node->next = NULL;
}

Node* shuffleMerge(Node* a, Node* b)
{
	Node dummy;
	Node* tail = &dummy;
	dummy.next = NULL;

	while (1)
	{
		// empty list cases
		if (a == NULL)
		{
			tail->next = b;
			break;
		}

		else if (b == NULL)
		{
			tail->next = a;
			break;
		}

		// common case: move two nodes to the tail
		else {
			tail->next = a;
			tail = a;
			a = a->next;

			tail->next = b;
			tail = b;
			b = b->next;
		}
	}

	return dummy.next;
}



int main()
{
	Node* head = NULL;
	Node* head2 = NULL;
	Node* merged = NULL;

	head = BuildOneTwoThree();
	Push(&head, 2);
	Push(&head, 0);

	head2 = BuildOneTwoThree();
	Push(&head2, 9);
	Push(&head2, 5);

	printf("List A: \n");
	printList(head);

	printf("\n\nList B: \n");
	printList(head2);

	merged = shuffleMerge(head, head2);
	printf("\n\nShuffled Merge of 2 lists:  \n");
	printList(merged);

	printf("\n\n \n");
	deleteList(merged);
}
