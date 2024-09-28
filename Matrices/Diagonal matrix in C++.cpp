#include <iostream>
using namespace std;

class Diagonal
{
private:
	int* A;
	int n;

public:
	Diagonal()
	{
		this->n = 2;
		A = new int[2];
	}

	Diagonal(int n)
	{
		this->n = n;
		A = new int[n];
	}

	~Diagonal()
	{
		delete[]A;
	}
	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
	int GetDimension() { return n; }

};

	void Diagonal:: Set(int i, int j, int x)
	{
		if (i == j)
			this->A[i - 1] = x;
	}

	int Diagonal::Get(int i, int j)
	{
		if (i == j)
			return this->A[i - 1];
		else
			return 0;
	}

	void Diagonal::Display()
	{
		int i, j;
		for (i = 0; i < this->n; i++)
		{
			for (j = 0; j < this->n; j++)
			{
				if (i == j)
					cout << this->A[i] << " ";
				else
					cout << 0 << " ";
			}
			cout << endl;
		}
	}


//int main()
//{
//	int n;
//	cout << "Enter dimension of diagonal matrix";
//	cin >> n;
//
//	 Diagonal m(n);
//
//	cout << "Enter diagonal elements"<<endl;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if(i==j){
//			int x;
//			cout << "Enter element: "<<endl;
//			cin >> x;
//			m.set(i, j, x);
//		}
//	}
//	m.Display();
//}
int main()
{
	int d;
	cout << "Enter Dimensions";
	cin >> d;

	Diagonal dm(d);

	int x;
	cout << "Enter All Elements";
	for (int i = 1; i <= d; i++)
	{
		for (int j = 1; j <= d; j++)
		{
			cin >> x;
			dm.set(i, j, x);
		}
	}

	dm.Display();
	return 0;
}