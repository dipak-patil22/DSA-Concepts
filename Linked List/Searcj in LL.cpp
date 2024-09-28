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

Node* Search(Node *A,int key)
{
    while (A != nullptr)
    {
        if (key == A->data)
            return A;
        A = A->next;
    }
    return nullptr;
}

Node* RecSearch(Node* A, int key)
{
    if (A == nullptr)
        return nullptr;
    if (key == A->data)
        return (A);

    return RecSearch(A->next, key);
}

int main()
{
    int A[5] = { 2,3,4,5,6 };

    Node* B = create(A, 5);

    Node* C = Search(B, 4);
    cout << C << endl;

    Node* D = RecSearch(B, 4);
    cout << D << endl;


}
