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

int isSorted(struct Node* p)
{
    int x = -65536;

    while (p != NULL)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;

}

void RemoveDuplicate(struct Node* p)
{
    struct Node* q = p->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }

}

int main()
{
    int A[5] = { 2,3,4,5,6 };
    Node* B = create(A, 5);
    //Display(B);
    cout << isSorted(B)<<endl;    // 0==Not sorted , 1==sorted


    int C[] = { 10,20,20,40,50,50,50,60 };
    Node* D = create(C,8);
    RemoveDuplicate(D);
    Display(D);
}
