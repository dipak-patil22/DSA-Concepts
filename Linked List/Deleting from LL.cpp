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
int Delete(struct Node* p, int index)
{
    struct Node* q = NULL;
    int x = -1, i;
    
    if (index < 1)
        return -1;
    if (index == 1)
    {
        q = p;
        x = p->data;
        p = p->next;
        delete q;
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;

    }


}


int main()
{
    int A[5] = { 2,3,4,5,6 };

    Node* B = create(A, 5);
    Delete(B, 3);
    Display(B);
    cout << endl;
}
