// Combination formula.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;

int C(int n, int r)
{
    if (r == 0 || r == n)
        return 1;
    else
        return C(n - 1, r - 1) + C(n - 1, r);

}


int main()
{
    int n = 4, r = 3;
    cout << C(n, r);

}

