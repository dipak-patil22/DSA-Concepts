

#include <iostream>
using namespace std;

void Print(int A[],int n)
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
void BubbleSort(int A[], int n)
{
    int flag = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                Swap(A[j], A[j + 1]);
                flag = 1;
            }

            if (flag == 0)
                return;
        }
    }

}

int main()
{
    int A[5] = { 8,5,7,3,2 };
    BubbleSort(A, 5);
    cout << "Bubble Sort " << endl;
    Print(A,5);
}
