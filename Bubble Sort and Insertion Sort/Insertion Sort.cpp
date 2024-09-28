#include <iostream>
using namespace std;

void Print(int A[], int n)
{
    cout << "A[]= ";
    //int n = sizeof(A) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        cout << "  " << A[i];
    }
}

void Swap(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}

void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = A[i];
        int j = i - 1;
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }

}

int main()
{
    int A[5] = { 8,5,7,3,2 };
    cout << "Insertion Sort " << endl;
    InsertionSort(A, 5);
    Print(A, 5);
}