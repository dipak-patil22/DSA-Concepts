

#include <iostream>
using namespace std;

void Print(int A[], int n)
{
    cout << "A[]= ";
    for (int i = 0; i < n; i++)
    {
        cout << "  " << A[i];
    }
}

void Swap(int& i, int& j)
{
    int temp = i;
    i = j;
    j = temp;
}
void SelectionSort(int A[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int k = i;
        int j = i;
        while (j < n-1)
        {
            j++;
            if (A[j] < A[k])
                k = j;
        }
        Swap(A[i], A[k]);
    }

}

int main()
{
    int A[5] = { 8,5,7,3,2 };
    SelectionSort(A, 5);
    cout << "Selection Sort " << endl;
    Print(A, 5);
}
