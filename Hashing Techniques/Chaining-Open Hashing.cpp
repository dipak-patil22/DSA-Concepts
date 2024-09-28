#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};


class HashTable
{
public:
	Node** HT;
	HashTable();
	~HashTable();
	int hash(int key);
	void Insert(int x);

	int Search(int key);

};

HashTable::HashTable()
{
	HT = new Node*[10];

	for (int i = 0; i < 10; i++)
		HT[i] = nullptr;
}
HashTable::~HashTable()
{
	for (int i = 0; i < 10; i++) {
		Node* p = HT[i];
		while (HT[i]) {
			HT[i] = HT[i]->next;
			delete p;
			p = HT[i];
		}
	}
	delete[] HT;
}

int HashTable::hash(int key) {
	return key % 10;
}
void HashTable::Insert(int key)
{
	int a = hash(key);

	Node* temp = new Node;
	temp->data = key;
	temp->next = nullptr;
	// Case: No nodes in the linked list
	if (HT[a] == nullptr)
	{
		HT[a] = temp;
	}
	else
	{
		Node* p = HT[a];
		Node* q = HT[a];

		// Traverse to find insert position
		while (p && p->data < key) {
			q = p;
			p = p->next;
		}
		// Case: insert position is first
		if (q == HT[a]) {
			temp->next = HT[a];
			HT[a] = temp;
		}
		else {
			temp->next = q->next;
			q->next = temp;
		}
	}
	return;
}

int HashTable::Search(int key) {
	int hIdx = hash(key);
	Node* p = HT[hIdx];
	while (p) {
		if (p->data == key) {
			return p->data;
		}
		p = p->next;
	}
	return -1;
}

int main()
{
	int A[] = { 16, 12, 25, 39, 6, 122, 5, 68, 75 };
	int n = sizeof(A) / sizeof(A[0]);
	HashTable H;
	for (int i = 0; i < n; i++) {
		H.Insert(A[i]);
	}
	cout << "Successful Search" << endl;
	int key = 6;
	int value = H.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;
	cout << "Unsuccessful Search" << endl;
	key = 95;
	value = H.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;

	return 0;
}
