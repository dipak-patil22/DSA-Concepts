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

struct Node* Concatenate(struct Node* A, struct Node* B)
{
    Node* head = A;
    while (A->next != nullptr)
    {
        A = A->next;
    }
    A->next = B;
    B = nullptr;

    return head;
}

struct Node* SortedMerge(struct Node* A, struct Node* B)
{
    Node* third = nullptr;
    Node* last  = nullptr;
    if (A->data < B->data)
    {
        third =last= A;
        A = A->next;
        last->next = nullptr;
    }
    else
    {
        third = last = B;
        B = B->next;
        last->next = nullptr;
    }

    while (A && B) {
        if (A->data < B->data)
        {
            last->next = A;
            last = A;
            A = A->next;
            last->next = nullptr;
        }
        else
        {
            last->next = B;
            last = B;
            B = B->next;
            last->next = nullptr;
        }
    }
    if (A)
    {
        last->next = A;
    }
    else
        last->next = B;

    return third;
}


int main()
{
    int A[5] = { 2,8,10,15,17};
    int C[5] = { 4,7,12,14,16};
    Node* B = create(A, 5);
    Node* D = create(C, 5);

    Node* E = Concatenate(B, D);
    Display(E);
    cout << endl;

    Node* F = SortedMerge(B, D);
    Display(F);

}
