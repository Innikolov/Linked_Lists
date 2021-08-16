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

 Node* SortedMerge( Node* a,  Node* b)
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

int main()
{
	Node* a;
	a = BuildOneTwoThree();
	Push(&a, 5);
	Push(&a, 2);
	Push(&a, 9);
	Push(&a, 0);
	Sort(&a);

	Node* b;
	b = BuildOneTwoThree();
	Push(&b, 6);
	Push(&b, 8);
	Push(&b, 0);
	Sort(&b);

	printf("List A: \n");
	printList(a);

	printf("\n\nList B: \n");
	printList(b);

	Node* merged;
	merged = SortedMerge(a, b);

	printf("\n\nSorted Merge List: \n");
	printList(merged);

	getchar();

}

