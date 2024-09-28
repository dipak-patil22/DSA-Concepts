#include <iostream>
using namespace std;

struct matrix
{
	int A[10];
	int n;
};

void set(matrix *s, int i, int j, int x)
{
	if (i == j)
		s->A[i - 1] = x;
}

int get(matrix g, int i, int j)
{
	if (i == j)
		return g.A[i - 1];
	else
		return 0;
}

void Display(matrix d)
{
	int i, j;
	for (i = 0; i < d.n; i++)
	{
		for (j = 0; j < d.n; j++)
		{
			if (i == j)
				cout << d.A[i]<<" ";
			else
				cout << 0<<" ";
		}
		cout << endl;
	}
}

int main()
{
	struct matrix m;
	m.n = 4;

	set(&m, 1, 1, 4); set(&m, 2, 2, 2); set(&m, 3, 3, 8); set(&m, 4, 3, 9); set(&m, 4, 4, 10);
	//Display(m);
	cout<<get(m, 3, 3);

}
