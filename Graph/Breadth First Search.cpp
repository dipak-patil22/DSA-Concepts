
#include <iostream>
#include<queue>

using namespace std;

void BFS(int A[][8], int vtx, int n)
{
	queue <int> Q;
	int* visited = new int[n];
	for (int i = 0; i < n; i++)
		visited[i] = 0;
	//Initial
	cout << "BSF: " << vtx;
	Q.emplace(vtx);
	visited[vtx] = 1;

	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();

		for (int v = 1; v < +n; v++)
		{
			if (A[u][v] == 1 && visited[v] == 0)
			{
				cout << " " << v;
				visited[v] = 1;
				Q.emplace(v);
			}
		}
	}
	cout << endl;
}


int main() {

	int A[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
				   {0, 0, 1, 1, 1, 0, 0, 0},
				   {0, 1, 0, 1, 0, 0, 0, 0},
				   {0, 1, 1, 0, 1, 1, 0, 0},
				   {0, 1, 0, 1, 0, 1, 0, 0},
				   {0, 0, 0, 1, 1, 0, 1, 1},
				   {0, 0, 0, 0, 0, 1, 0, 0},
				   {0, 0, 0, 0, 0, 1, 0, 0} };

	cout << "Vertex: 1 -> " << flush;
	BFS(A,1, 8);

	cout << "Vertex: 4 -> " << flush;
	BFS(A,4, 8);


	return 0;
}