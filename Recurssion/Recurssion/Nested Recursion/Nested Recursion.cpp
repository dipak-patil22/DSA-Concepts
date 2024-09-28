// Nested Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int fun(int n)
{
    if (n > 100)
        return n - 10;
    else
        fun(fun(n + 11));
}


int main()
{
    int x = 96;
    cout<<fun(96);
}

