#include <iostream>
using namespace std;

int main()
{
	//Method 1
	int A[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	cout << "Elements of array A" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j< 4; j++)
			cout << A[i][j]<<"  ";
	}

	//Method 2

	int* B[3];
	B[0] = new int[4];
	B[1] = new int[4];
	B[2] = new int[4];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			B[i][j] = i + j;
	}
	cout << endl << endl << endl << "Elements of array B" << endl ;


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << B[i][j]<<"  ";
	}

	//Method 3

	int** C;
	C = new int* [3];
	C[0] = new int[4];
	C[1] = new int[4];
	C[2] = new int[4];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			C[i][j] = i + j+5;
	}

	cout << endl << endl << endl<< "Elements of array C" << endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << C[i][j]<<"  ";
	}

}
