#include <iostream>
using namespace std;

int main()
{
	int size; 
	cout << "Size of array =  ";
	cin >> size;
	//int A[n];	// We cant define array like this for variable size hense we need to use pointer,

	int* A;
	A = new int[size];
}