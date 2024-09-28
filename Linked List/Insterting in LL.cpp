#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

struct Node* create(int B[], int size)
{
	Node* head = new Node;
	head->data = B[0];
	head->next = nullptr;

	Node* last;
	last = head;

	for (int i = 1; i < size; i++)
	{
		Node* temp = new Node;
		temp->data = B[i];
		temp->next = nullptr;

		last->next = temp;
		last = temp;
	}
	return head;
}
void Display(struct Node* p)
{
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
void Insert(struct Node *p, int pos, int x)
{
	struct Node* t;
	int i;
	Node *head = new Node;
	head = p;

	if (head==nullptr)
		return;
	t = new Node;
	t->data = x;

	if (pos == 0)
	{
		t->next = head;
		head = t;
	}
	else
	{
		for (i = 1; i < pos; i++)
			p = p->next;
		t->next = p->next;
		p->next = t;

	}
}

void InsertLast(struct Node *A,int x)
{	
	Node *temp = new Node;
	Node* last = new Node;
	last = A;

	temp->data = x;
	temp->next = nullptr;


	if (A == nullptr)
		A = last = temp;
	while (last->next != nullptr)
	{
		last = last->next;
	}
	if (last->next == nullptr)
		last->next = temp;
}

void InsertInSorted(struct Node* A, int x)
{
	Node* temp = new Node;
	struct Node* P = nullptr;
	struct Node* Q=nullptr;
	P = A;

	temp->data = x;
	temp->next = nullptr;


	while (P->data < temp->data)
	{
		Q = P;
		P = P->next;
	}

	Q->next = temp;
	temp->next = P;
}

int main()
{

	int A[] = { 10,20,30,40,50 };
	Node *B = create(A, 5);
	//Display(B);
	cout << endl;
	//Insert(B, 0, 5);
	//InsertLast(B,60);
	InsertInSorted(B, 45);
	Display(B);
	return 0;
}


//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int data;
//	struct Node* next;
//}*first = NULL;
//void create(int A[], int n)
//{
//	int i;
//	struct Node* t, * last;
//	first = (struct Node*)malloc(sizeof(struct Node));
//	first->data = A[0];
//	first->next = NULL;
//	last = first;
//
//	for (i = 1; i < n; i++)
//	{
//		t = (struct Node*)malloc(sizeof(struct Node));
//		t->data = A[i];
//		t->next = NULL;
//		last->next = t;
//		last = t;
//	}
//}
//void Display(struct Node* p)
//{
//	while (p != NULL)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//}
//void Insert(struct Node* p, int index, int x)
//{
//	struct Node* t;
//	int i;
//
//	if (index < 0 )
//		return;
//	t = (struct Node*)malloc(sizeof(struct Node));
//	t->data = x;
//
//	if (index == 0)
//	{
//		t->next = first;
//		first = t;
//	}
//	else
//	{
//		for (i = 0; i < index - 1; i++)
//			p = p->next;
//		t->next = p->next;
//		p->next = t;
//
//	}
//
//
//}
//int main()
//{
//
//	int A[] = { 10,20,30,40,50 };
//	create(A, 5);
//
//
//	Insert(first, 0, 5);
//	Display(first);
//	return 0;
//}