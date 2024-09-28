#include <iostream>
using namespace std;

struct Array
{
	int A[20];
	int size;
	int length;

};

void Append(struct Array *arr, int x)
{
	if (arr->length < arr->size) {
		arr->A[arr->length] = x;
		arr->length++;
	}
}

void Insert(struct Array* arr,int index, int x)
{
	if (arr->length+1 < arr->size)
	{
		for (int i = arr->length; i > index; i--)
			arr->A[i] = arr->A[i - 1];
		arr->length++;
	}
	arr->A[index] = x;
}

void Delete(struct Array* arr, int index)
{
	for (int i = index; i < arr->length; i++)
	{
		arr->A[i] = arr->A[i + 1];
	}
	arr->length--;
}


void Display(struct Array arr)
{
	cout << endl << "The array:" << endl;
	for (int i = 0; i < arr.length; i++)
		cout << arr.A[i] << " ";
}

int main()
{
	struct Array arr = { {2,4,6,7,9},20,5 };
	Append(&arr, 12);
	Display(arr);

	Insert(&arr, 4, 16);
	Display(arr);

	Delete(&arr, 4);
	Display(arr);
}