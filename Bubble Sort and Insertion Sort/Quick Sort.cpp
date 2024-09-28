#include <iostream>

using namespace std;

template <class T>
void Print(T& vec, int n, string s) {
    cout << s << ": [" << flush;
    for (int i = 0; i < n; i++) {
        cout << vec[i] << flush;
        if (i < n - 1) {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Quick Sort using INT_MAX or INFINITY
int partitionA(int A[], int low, int high) {
    int pivot = A[low];
    int i = low;
    int j = high;

    do {
        // Increment i as long as elements are smaller/equal to pivot
        do { i++; } while (A[i] <= pivot);

        // Decrement j as long as elements are larger than pivot
        do { j--; } while (A[j] > pivot);

        if (i < j) {
            swap(&A[i], &A[j]);
        }
    } while (i < j);

    swap(&A[low], &A[j]);
    return j;
}

void QuickSortA(int A[], int low, int high) {
    if (low < high) {
        int j = partitionA(A, low, high);
        QuickSortA(A, low, j);
        QuickSortA(A, j + 1, high);
    }
}



int main() {

    cout << "Using INT_MAX or Infinity" << endl;
    int A[] = { 3, 7, 9, 10, 6, 5, 12, 4, 11, 2, 32767 };
    int n = sizeof(A) / sizeof(A[0]);
    Print(A, n - 1, "\t\tA");

    QuickSortA(A, 0, n - 1);
    Print(A, n - 1, " Sorted A");
    cout << endl;



    return 0;
}