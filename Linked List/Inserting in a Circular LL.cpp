#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList(int A[], int n);
    void Display();
    int Length(Node* p);
    void recursiveDisplay(Node* p);
    Node* getHead() { return head; }
    ~CircularLinkedList();
    void InsertCLL(int index, int x);
    int Delete(int index);
};

CircularLinkedList::CircularLinkedList(int* A, int n) {

    Node* t;
    Node* tail;

    head = new Node;

    head->data = A[0];
    head->next = head;
    tail = head;

    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}

void CircularLinkedList::Display() {
    Node* p = head;
    do {
        cout << p->data << " -> " << flush;
        p = p->next;
    } while (p != head);
    cout << endl;
}

int CircularLinkedList::Length( Node* p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;

    } while (p != head);
    return len;
}


CircularLinkedList::~CircularLinkedList() {
    Node* p = head;
    while (p->next != head) {
        p = p->next;
    }

    while (p != head) {
        p->next = head->next;
        delete head;
        head = p->next;
    }

    if (p == head) {
        delete head;
        head = nullptr;
    }

}

void CircularLinkedList::InsertCLL(int index, int x)
{
	Node* p = nullptr;
	p = head;
	Node* temp = new Node;
	temp->data = x;
	if (index == 0)
	{
		if (head == NULL)
		{
			head = temp;
			head->next = head;
		}
		else
		{
			temp->next = head;
			while (p->next != head)
				p = p->next;
			p->next = temp;
			head = temp;
		}
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
			p = p->next;
		temp->next = p->next;
		p->next = temp;
	}
}

int CircularLinkedList::Delete(int index)
{
    Node* q;
    int i, x;
    Node* p = head;
    if (index <0 || index >Length(head))
        return -1;
    if (index == 1)
    {
        while (p->next != head)
            p = p->next;
        x = head->data;
        if (head == p)
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete (q);
    }
    return x;
}

int main()
{
	int A[] = { 1,2,3,4,5 };
	CircularLinkedList l(A, 5);
	
	l.Display();
	cout << endl;
	
	l.InsertCLL(0, 9);
	l.Display();
	cout << endl;

	l.InsertCLL(3, 22);
	l.Display();

    l.Delete(3);
    l.Display();

	return 0;
}