
// Fibonacci Series using memomrization


#include <iostream>
using namespace std;

int fib(int n)
{
    int F[10];
    
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (fib(n - 2) == -1)
        {
            F[n - 2] = fib(n - 2);
        }
        if (fib(n - 1) == -1)
        {
            F[n - 1] == fib(n - 1);
        }
        return fib(n - 2) + fib(n - 1);
    }
}

int main()
{
    int n;
    cout << "Enter the value of n = ";
    cin >> n;

    cout<< "Value of Fibonacci series of n = "<< fib(n);
}

