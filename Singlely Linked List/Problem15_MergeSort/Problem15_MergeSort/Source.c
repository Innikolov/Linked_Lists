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

Node* SortedMerge(Node* a, Node* b)
{
	/* a dummy first node to hang the result on */
	Node dummy;

	/* tail points to the last result node  */
	Node* tail = &dummy;

	/* so tail->next is the place to add new nodes
	  to the result. */
	dummy.next = NULL;
	while (1)
	{
		if (a == NULL)
		{
			/* if either list runs out, use the
			   other list */
			tail->next = b;
			break;
		}
		else if (b == NULL)
		{
			tail->next = a;
			break;
		}
		if (a->data <= b->data)
			MoveNode(&(tail->next), &a);
		else
			MoveNode(&(tail->next), &b);

		tail = tail->next;
	}
	return(dummy.next);
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

void MergeSort(Node** headRef) {

	Node* newNode = NULL;
	Node* a = NULL;
	Node* b = NULL;

	if (newNode == NULL || newNode->next == NULL) {
		return;
	}

	frontBackSplit(newNode, &a, &b);
	MergeSort(&a);
	MergeSort(&b);

	*headRef = SortedMerge(a, b);

}

int main()
{
	Node* a = NULL;

	Push(&a, 15);
	Push(&a, 10);
	Push(&a, 5);
	Push(&a, 20);
	Push(&a, 3);
	Push(&a, 2);
	printf("List is: \n");
	printList(a);
	/* Sort the above created Linked List */
	MergeSort(&a);

	printf("\n\nSorted Linked List is: \n");
	printList(a);

	getchar();
}

