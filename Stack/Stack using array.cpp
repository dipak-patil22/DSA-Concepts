

#include <iostream>
using namespace std;

class Stack {
private:
    int size;
    int top;
    int* s;

public:
    Stack(int size);
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isFull();
    int isEmpty();
    void display();
    int stackTop();
};

Stack::Stack(int size) 
{
    Stack::size = size;
    top = -1;
    s = new int(size);
}

Stack::~Stack()
{
    delete s;
    s = nullptr;
}

void Stack::push(int x)
{
    if (isFull())
        cout << "It is Stack Overflow";
    else
    {
        top++;
        s[top] = x;
    }
}

int Stack::pop()
{
    int x = -1;
    if (isEmpty())
        cout << "Stack is Underflow";
    else
    {
        x = s[top];
        top--;
    }
    return x;
}

int Stack::peek(int index)
{
    int x = -1;
    if (top - index + 1 < 0 || top - index + 1 == size) {
        cout << "Invalid position!" << endl;
    }
    else {
        x = s[top - index + 1];         // "top - index +1" is just a conversion formula to convert index
    }                                   // to position and formula is obtained by observation
    return x;
}

int Stack::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int Stack::isFull()
{
    if (top == size - 1)
        return 1;
    else
        return 0;
}

void Stack::display() {
    for (int i = top; i >= 0; i--) {
        cout << s[i] << " | " << flush;
    }
    cout << endl;
}

int Stack::stackTop() {
    if (isEmpty()) {
        return -1;
    }
    return s[top];
}


int main()
{
    int A[] = { 1, 3, 5, 7, 9 };

    Stack stk(sizeof(A) / sizeof(A[0]));

    // Populate stack with array elements
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        stk.push(A[i]);
    }
    stk.push(11);

    cout << "Stack full: " << stk.isFull() << endl;

    // Display stack;
    cout << "Stack: " << flush;
    stk.display();

    // Peek
    cout << "Peek at 0th: " << stk.peek(0) << endl;
    cout << "Peek at 3rd: " << stk.peek(3) << endl;
    cout << "Peek at 10th: " << stk.peek(10) << endl;

    // Top element
    cout << "Top element: " << stk.stackTop() << endl;

    // Pop out elements from stack
    cout << "Popped out elements: " << flush;
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        cout << stk.pop() << ", " << flush;
    }
    cout << endl;
    stk.pop();

    cout << "Stack empty: " << stk.isEmpty() << endl;

    return 0;
}
