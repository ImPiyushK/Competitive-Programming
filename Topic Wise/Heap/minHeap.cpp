#include<bits/stdc++.h>
using namespace std;

class MinHeap
{
	vector<int> heap;
	int n;

	void heapify(int i)
	{
		int c1 = 2 * i + 1, c2 = 2 * i + 2;
		int min = i;
		if (c1 < n && heap[c1] < heap[min])
			min = c1;
		if (c2 < n && heap[c2] < heap[min])
			min = c2;

		if (min != i)
		{
			swap(heap[i], heap[min]);
			heapify(min);
		}
	}

public:
	MinHeap()
	{
		n = 0;
	}
	MinHeap(int ar[], int size)
	{
		for (int i = 0 ; i < size ; ++i)
			heap.push_back(ar[i]);
		n = size;
		for (int i = n / 2 ; i >= 0 ; --i)
		{
			heapify(i);
		}
	}
	void printHeap()
	{
		for (int i = 0 ; i < n ; ++i)
			cout << heap[i] << " ";
		cout << endl;
	}
	int extractMin()
	{
		if (n == 0)
			return INT_MIN;

		swap(heap[0], heap[n - 1]);
		n--;
		heapify(0);

		return heap[n];
	}
	void percolate_up(int n)
	{
		if (n == 0)
			return;
		int parent = (n - 1) / 2;

		if (parent >= 0 && heap[n] < heap[parent])
		{
			swap(heap[n], heap[parent]);
			percolate_up(parent);
		}
	}
	void insert(int key)
	{
		if (heap.size() == n)
			heap.push_back(key);
		else
			heap[n] = key;
		n++;
		percolate_up(n - 1);
	}
};

int main()
{
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0 ; i < n ; ++i)
		cin >> ar[i];

	MinHeap heap = MinHeap(ar, n);
	heap.printHeap();
	cout << "Min: " << heap.extractMin() << endl;
	heap.printHeap();
	int key;
	cin >> key;
	heap.insert(key);
	heap.printHeap();
}