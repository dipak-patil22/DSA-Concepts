#include <iostream>
using namespace std;

int search(int arr[],int size, int k)
{

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == k)
            return  i;
    }

    return -1;              //If element is not present in array
}

int main()
{
    int size = 10;
    int A[10] = { 1,4,3,5,7,8,6,9,2 };
    int key = 7;
    int index;

    index = search(A, size,key);
    cout << index;

}
