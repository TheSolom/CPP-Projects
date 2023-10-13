#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
	int size{};
	int capacity{};
	int* arr;

	int left(int node) {
		int p = 2 * node + 1;

		if (p >= size)
			return -1;
		return p;
	}
	int right(int node) {
		int p = 2 * node + 2;

		return p >= size ? -1 : p;
	}
	int parent(int node) {
		return node == 0 ? -1 : (node - 1) / 2;
	}

	void heapify_up(int child_pos) { // O(logn)
		int parent_pos = parent(child_pos);

		if (child_pos == 0 || arr[parent_pos] < arr[child_pos])
			return;

		swap(arr[parent_pos], arr[child_pos]);
		heapify_up(parent_pos);
	}

	void heapify_down(int parent_pos) {	// O(logn)
		int child_pos = left(parent_pos);
		int right_child = right(parent_pos);

		if (child_pos == -1) // no children
			return;
		// is right smaller than left?
		if (right_child != -1 && arr[right_child] < arr[child_pos])
			child_pos = right_child;

		if (arr[parent_pos] > arr[child_pos]) {
			swap(arr[parent_pos], arr[child_pos]);
			heapify_down(child_pos);
		}
	}

	void heapify() {	// Fold algorithm - O(n)
		for (int i = size / 2 - 1; i >= 0; i--)
			heapify_down(i);
	}

public:
	MinHeap(int capacity) : capacity(capacity) {
		arr = new int[capacity] {};
		size = 0;
	}

	MinHeap(int capacity, const vector<int>& v) : capacity(capacity) {
		if ((int)v.size() <= capacity)
		{
			arr = new int[capacity] {};
			size = (int)v.size();

			for (int i = 0; i < (int)v.size(); i++)
				arr[i] = v[i];

			heapify();
		}
		else
			cout << "Vector size is greater than heap capacity!\n";
	}

	~MinHeap() {
		arr = nullptr;
		delete[] arr;
	}

	void push(int item) {
		if (!isFull()) {
			arr[size++] = item;

			heapify_up(size - 1);
		}
		else
			cout << "Full!\n";
	}

	int top() {
		if (!isEmpty())
			return arr[0];
		else
			cout << "Empty!\n";
	}

	void pop() {
		if (!isEmpty()) {
			arr[0] = arr[--size];

			heapify_down(0);
		}
		else
			cout << "Empty!";
	}

	bool isFull() {
		return size + 1 > capacity;
	}

	bool isEmpty() {
		return size == 0;
	}

	void print_less_than(int val, int parent_pos = 0) {
		if (parent_pos == -1 || arr[parent_pos] >= val) 
			return;

		cout << arr[parent_pos] << " ";

		print_less_than(val, left(parent_pos));
		print_less_than(val, right(parent_pos));
	}

	void print_less_than_iterative(int val) {
		int i = 0, steps{};
		while (arr[i] != val) {
			if (arr[i] < val)
				cout << arr[i] << " ";

			i++, steps++;
		}
		cout << "\nhow many steps: " << steps;
	}

	bool is_heap_array(int* p, int n) {
		// Take our data copy. Replace. Use. Return data
		int* old_arr = arr;
		int old_size = size;

		arr = p;
		size = n;

		for (int i = 0; i < size; i++)
		{
			int left_pos = left(i);
			int right_pos = right(i);

			if (left_pos == -1 && right_pos > 0)
				return false;
			if ((left_pos > 0 && arr[i] > arr[left_pos]) || ( right_pos > 0 && arr[i] > arr[right_pos]))
				return false;
		}

		size = old_size;
		arr = old_arr;

		return true;
	}

	void heap_sort(int* p, int n) {	// O(nlogn)
		if (n <= 1)
			return;

		int* old_arr = arr;
		int old_size = size;

		size = n;
		arr = p;

		heapify();	// O(n)

		while (size--) {	// O(nlogn)
			swap(arr[0], arr[size]);
			heapify_down(0);
		}

		// reverse
		for (int i = 0; i < n / 2; ++i)
			swap(arr[i], arr[n - i - 1]);

		size = old_size;
		arr = old_arr;
	}
};

class MaxHeap {
	int size{};
	int capacity{};
	int* arr;

	int left(int node) {
		int p = 2 * node + 1;

		if (p >= size)
			return -1;
		return p;
	}
	int right(int node) {
		int p = 2 * node + 2;

		return p >= size ? -1 : p;
	}
	int parent(int node) {
		return node == 0 ? -1 : (node - 1) / 2;
	}

	void heapify_up(int child_pos) { // O(logn)
		int parent_pos = parent(child_pos);

		if (child_pos == 0 || arr[parent_pos] > arr[child_pos])
			return;
		
		swap(arr[parent_pos], arr[child_pos]);
		heapify_up(parent_pos);
	}

	void heapify_down(int parent_pos) { // O(logn)
		int child_pos = left(parent_pos);
		int right_child = right(parent_pos);

		if (child_pos == -1) // no children
			return;
		// is right bigger than left?
		if (right_child != -1 && arr[right_child] > arr[child_pos])
			child_pos = right_child;

		if (arr[parent_pos] < arr[child_pos]) {
			swap(arr[parent_pos], arr[child_pos]);
			heapify_down(child_pos);
		}
	}

	void heapify() {	// Fold algorithm - O(n)
		for (int i = size / 2 - 1; i >= 0; i--)
			heapify_down(i);
	}

public:
	MaxHeap(int capacity) : capacity(capacity) {
		arr = new int[capacity] {};
		size = 0;
	}

	MaxHeap(int capacity, const vector<int>& v) : capacity(capacity) {
		if ((int)v.size() <= capacity)
		{
			arr = new int[capacity] {};
			size = (int)v.size();

			for (int i = 0; i < (int)v.size(); i++)
				arr[i] = v[i];

			heapify();
		}
		else
			cout << "Vector size is greater than heap capacity!\n";
	}

	~MaxHeap() {
		arr = nullptr;
		delete[] arr;
	}

	void push(int item) {
		if (!isFull()) {
			arr[size++] = item;

			heapify_up(size - 1);
		}
		else
			cout << "Full!\n";
	}

	int top() {
		if (!isEmpty())
			return arr[0];
		else
			cout << "Empty!\n";
	}

	void pop() {
		if (!isEmpty()) {
			arr[0] = arr[--size];

			heapify_down(0);
		}
		else
			cout << "Empty!";
	}

	bool isFull() {
		return size + 1 > capacity;
	}

	bool isEmpty() {
		return size == 0;
	}
};


void test_minheap_nlogn() {
	MinHeap heap(100);

	vector<int> v { 2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30 };

	for (int i = 0; i < (int)v.size(); ++i)
		heap.push(v[i]);

	heap.print_less_than_iterative(10);
}

void creat_maxheap_n() {
	vector<int> v { 2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30 };
	MaxHeap heap(100, v);

	while (!heap.isEmpty()) {
		cout << heap.top() << " ";
		heap.pop();
	}
}

void test_is_heap_array() {
	vector<int> v { 2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30 };
	MinHeap heap(100, v);

	int arr[]{ 2, 5, 12, 7,6, 22, 14, 19, 10, 17, 8, 37, 25, 30 };
	cout << heap.is_heap_array(arr, 14) << "\n";	// 1
	swap(arr[0], arr[5]);
	cout << heap.is_heap_array(arr, 14) << "\n";	// 0
}

void test_heap_sort() {
	const int SZ = 14;
	int arr[SZ]{ 2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30 };
	MinHeap heap(100);

	heap.heap_sort(arr, SZ);

	for (int i = 0; i < SZ; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main() {
	test_heap_sort();
}