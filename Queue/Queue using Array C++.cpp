
#include <iostream>
using namespace std;

class Queue
{
private: 
    int size;
    int front;
    int rear;
    int* Q;
public:
    Queue(int size);
    ~Queue();
    void enqueue(int x);
    int dequeue();
    void display();
};

Queue::Queue(int size)
{
    this->size = size;
    front = rear = -1;
    Q = new int (size);
 
}

Queue::~Queue()
{
    delete [] Q;
    Q = nullptr;
}

void Queue::enqueue(int x)
{
    if (rear == size - 1)
        cout << "Queue is full";
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (front == rear)
        cout << "Queue is empty";
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::display() {
    for (int i = front + 1; i <= rear; i++) {
        cout << Q[i] << flush;
        if (i < rear) {
            cout << " <- " << flush;
        }
    }
    cout << endl;
}

int main()
{
    Queue q(7);
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(8);
    q.enqueue(10);
    q.enqueue(13);
    q.dequeue();
    q.display();
}

