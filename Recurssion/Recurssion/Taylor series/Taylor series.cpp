// Taylor series.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>  
using namespace std;

int pow(int m, int n)
{
    if (n == 0)
        return 1;
    else
        return pow(m, n - 1) * m;
}

int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return fact(n - 1) * n;
}

float taylor(int m, int n)
{
    if (m == 0 || n == 0)
        return 1;
    else
        return taylor(m, n - 1) + (float(pow(m, n)) / float(fact(n)));
}

int main()
{
    cout << taylor(2,3);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
