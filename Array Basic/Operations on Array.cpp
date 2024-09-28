#include <iostream>
using namespace std;

struct Array
{
	int* A;
	int size;
	int length;
};

void Display(struct Array arr)
{
	cout << endl << "The array:" << endl;
	for (int i =0 ; i < arr.length; i++)
		cout << arr.A[i] << " ";
}

int main()
{
	struct Array arr;
	cout << "Enter size of array= ";
	cin >> arr.size;

	arr.A = new int[arr.size];
	arr.length = 0;

	int n;
	cout << "Enter no. of elements= ";
	cin >> n;
	arr.length = n;

	cout << "Enter " << n << " all elemnts:" << endl;
	int j;
	for (int i = 0; i < n; i++)
	{
		cin >> arr.A[i];
		//arr.A[i] = j;
	}

	Display(arr);
}