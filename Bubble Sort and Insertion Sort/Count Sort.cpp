

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
int Max(int A[], int n) {
    int max = -32768;
    for (int i = 0; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

void CountSort(int A[], int n) {
    int max = Max(A, n);

    // Create count array
    int* count = new int[max + 1];

    // Initialize count array with 0
    for (int i = 0; i < max + 1; i++) {
        count[i] = 0;
    }

    // Update count array values based on A values
    for (int i = 0; i < n; i++) {
        count[A[i]]++;
    }

    // Update A with sorted elements
    int i = 0;
    int j = 0;
    
    for (j = 0; j < max + 1; j++)
    {
        while (count[j] > 0)
        {
            A[i] = j;
            i++;
            count[j]--;
        }
    }
    // Delete heap memory
    delete[] count;
}


int main()
{
    int A[] = { 8,5,7,3,2,7 };
    int n = sizeof(A) / sizeof(A[0]);
    CountSort(A, n);
    cout << "Count Sort " << endl;
    Print(A, 5);
}
