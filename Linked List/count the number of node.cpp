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

int CountNode(struct Node* C)
{
    int count = 0;
    while (C != nullptr)
    {
        count++;
        C = C->next;
    }
    return count;
}

int RecCountNode(struct Node* D)
{
    if (D == nullptr)
        return 0;
    else
        return RecCountNode(D->next) + 1;
}


int main()
{
    int A[5] = { 2,3,4,5,6 };

    Node* B = create(A, 5);

    int NoOfNode = CountNode(B);
    cout << "No of Node = "<< NoOfNode<<endl;

    int recNoOfNode = RecCountNode(B);
    cout << "No of Node = " << recNoOfNode << endl;

}

