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


int SumNode(struct Node* C)
{
    int sum = 0;
    while (C != nullptr)
    {
        sum=sum + C->data;
        C = C->next;
    }
    return sum;
}

int RecSumNode(struct Node* D)
{
    if (D == nullptr)
        return 0;
    else
        return RecSumNode(D->next) + D->data;
}

int Max(struct Node* p)
{
    int max = INT32_MIN;

    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;

}
int RMax(struct Node* p)
{
    int x = 0;

    if (p == 0)
        return INT32_MIN;
    x = RMax(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}
int main()
{
    int A[5] = { 2,3,8,5,6 };

    Node* B = create(A, 5);

    int SumOfNode = SumNode(B);
    cout << "Sum of Node = " << SumOfNode << endl;

    int recSumOfNode = RecSumNode(B);
    cout << "Sum of Node = " << recSumOfNode << endl;

    cout << "Maximum Element in Node = " << Max(B)<<endl;

}

