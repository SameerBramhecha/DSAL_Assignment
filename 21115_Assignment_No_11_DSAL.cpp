/*Implement the Heap sort algorithm implemented in CPP / Java demonstrating heap
data structure with modularity of programming language*/
#include<iostream>
using namespace std;
class HeapSort
{
public:
	void heapify(int*, int, int);
	void heapsort();
	void display(int*,int n);
};
void HeapSort::heapify(int* a, int n, int i)
{
	int largest, left, right;
	largest = i;
	left = (2 * i) +1;
	right = (2 * i) + 2;
	if (left<n && a[left]>a[largest])
	{
		largest = left;
	}
	if (right<n && a[right]>a[largest])
	{
		largest = right;
	}
	if (largest != i)
	{
		cout << "Swapping " << a[i] << " , " << a[largest] << endl;
		int temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		heapify(a, n, largest);
	}
}

void HeapSort::heapsort()
{
	int n;
	cout << "Enter no of elements to be inserted: " << endl;
	cin >> n;
	int *a;
	a = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter element: "<< (i+1) << endl;
		cin >> a[i];
		for (int i = (n / 2) - 1; i >= 0; i--)
			{
				heapify(a, n, i);
			}
	}
	cout<<"\nInsertion Complete."<<endl<<endl;
	cout << "Before Sorting: " << endl;
	display(a,n);cout<<endl;
	cout<<"\nStarting to delete:"<<endl;
	for (int i = n - 1; i >= 0; i--)
	{

		cout << "Swapping " << a[0] << " , " << a[i] << endl;
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapify(a, i, 0);
		cout<<"Deleted "<<a[i]<<endl<<endl;
	}
	cout << "After Sorting: " << endl;
	display(a,n);
}
void HeapSort::display(int *a,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
int main()
{
	HeapSort h;
	h.heapsort();
	return 0;
}

