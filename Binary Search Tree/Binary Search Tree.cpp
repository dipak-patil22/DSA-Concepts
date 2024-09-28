
#include <iostream>
using namespace std;

class Node
{
public:
	Node* lchild;
	int data;
	Node* rchild;
};

class BST
{
private:
	Node* root;
public:
	BST() { root = nullptr; }
	void Insert(int key);
	Node* Search(int key);
	void Inorder(Node* p);
	Node* getRoot() { return root; }
};

void BST::Insert(int key)
{
	Node* t = root;
	Node* p;
	Node* r=nullptr;

	//if root is null or empty
	if (root == nullptr)
	{
		p = new Node;
		p->data = key;
		p->lchild = p->rchild = nullptr;
		root = p;
		return;
	}
	if (t != nullptr)
	{
		r = t;
		if (key == t->data)
			return;
		else if (key < t->data)
			t = t->lchild;
		else
			t = t->rchild;
	}
	// Now t points at NULL and r points at insert location
	p = new Node;
	p->data = key;
	p->lchild = p->rchild = nullptr;
	if (p->data < r->data)
		r->lchild = p;
	else
		r->rchild = p;

}

Node* BST::Search(int key) {
	Node* t = root;
	while (t != nullptr) {
		if (key == t->data) {
			return t;
		}
		else if (key < t->data) {
			t = t->lchild;
		}
		else {
			t = t->rchild;
		}
	}
	return nullptr;
}

void BST::Inorder(Node* p) {
	if (p) {
		Inorder(p->lchild);
		cout << p->data << ", " << flush;
		Inorder(p->rchild);
	}
}

int main()
{
	BST bst;

	// Insert
	bst.Insert(10);
	bst.Insert(5);
	bst.Insert(20);
	bst.Insert(8);
	bst.Insert(30);


	// Search
	Node* temp = bst.Search(2);
	if (temp != nullptr) {
		cout << temp->data << endl;
	}
	else {
		cout << "Element not found" << endl;
	}

	// Inorder traversal
	bst.Inorder(bst.getRoot());
	cout << endl;
}

