

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
void Merge(int A[], int m, int B[], int n, int C[])
{
    int i = 0; int j = 0; int k = 0;
    while (i < m || j < n)
    {
        if (i < m && A[i] <= B[j])
        {
            C[k]=A[i];
            i++;
        }
        else if (j < n)
        {
            C[k]=B[j];
            j++;
        }1111111
        k++;
    }
    return;
}

int main()
{
    int A[] = { 2,10,18,20,23 };
    int B[] = { 4,9,19,25 };

    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);

    int* C = new int(m + n);
    Merge(A, m,B,n,C);
    
    cout << " Merge C[] = ";
    for (int i = 0; i < (m + n); i++)
        cout << " " << C[i];
   // cout << "Merge " << endl;
    //Print(C, m+n);
}
