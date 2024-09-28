#include <iostream>
#include<stdio.h>

using namespace std;

class Node
{
public:
	Node* lchild;
	int data;
	Node* rchild;
};

class Queue
{
private:
	int front;
	int rear;
	int size;
	Node** Q; // as Q is it is going to store the address of Node i.e. Node*
public:
	Queue(int size)
	{
		rear = front = -1;
		this->size = size;
		Q = new Node * [this->size];
	}
	void enque(Node* x);
	Node* dequeue();
	int isEmpty();
};

void Queue::enque(Node* x)
{
	if (rear == size - 1)
		cout << "Queue is full";
	else
	{
		rear++;
		Q[rear] = x;
	}
}

Node* Queue::dequeue()
{
	Node* x =nullptr;
	if (front == rear)
		cout << "Queue is empty";
	else
	{
		front++;
		x = Q[front];
	}
	return x;
}

int Queue::isEmpty()
{
	if (front == rear)
		return true;
	else
		return false;
}

class Tree
{
	Node* root;
public:
	Tree() { root = nullptr; };
	void CreateTree();
};

void Tree::CreateTree()
{
	int x;
	Node* p,*t;
	Node*  root= new Node;
	cout << "Enter the value of root node = ";
	cin >> x;
	cout << endl;
	root->data = x;
	root->lchild = root->rchild = nullptr;
	Queue q(100);
	q.enque(root);
	
	while (!q.isEmpty())
	{
		p = q.dequeue();
		cout << "Enter the value of left child of " << p->data << " = ";
		cin >> x;
		cout << endl;

		if (x != -1)
		{
			
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = nullptr;
			p->lchild = t;
			q.enque(t);
		}

		cout << "Enter the value of right child of " << p->data << " = ";
		cin >> x;
		cout << endl;
		if (x != -1)
		{
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = nullptr;
			p->rchild = t;
			q.enque(t);
		}

	}
}

int main()
{
	Tree t;
	t.CreateTree();
}
