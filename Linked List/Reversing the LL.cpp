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

void Revese1(struct Node* A)        //by reversing the elements   
{
    Node* first = A;
    Node* P = first;
    int arr[10];
    int i = 0;

    while (P != nullptr)
    {
        arr[i] = P->data;
        P = P->next;
        i++;
    }
    P = first;
    i--;
    while(P!=nullptr)
    {
        P->data = arr[i];
        P = P->next;
        i--;
    }
}

Node* Reverse2(struct Node* A)      //reversing by a links
{
    Node* first = A;
    Node* p = first;
    Node* q = nullptr;
    Node* r =nullptr;
    while (p != nullptr)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
    return first;
}

//void Reverse3(struct Node* q, struct Node* p)     //for recurssive reverse
//{
//    if (p)
//    {
//        Reverse3(p, p->next);
//        p->next = q;
//    }
//    else
//        first = q;
//}

int main()
{
    int A[5] = { 2,3,4,5,6 };

    Node* B = create(A, 5);
    //Revese1(B);
    Display(B);

    Reverse2(B);
    Display(B);

    cout << endl;
}
