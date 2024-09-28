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

void Display(struct Node* A)
{
    Node* temp = A;
    while (temp != nullptr)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
}


int main()
{
    int A[5] = { 2,3,4,5,6 };

    Node* B = create(A, 5);
    Display(B);
    cout << endl;
}
