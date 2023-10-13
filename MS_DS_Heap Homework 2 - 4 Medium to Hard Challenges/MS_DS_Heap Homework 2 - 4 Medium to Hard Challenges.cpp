#include <vector>
#include <iostream>
#include <cassert>
#include <queue>
using namespace std;

class BinaryTree {
private:
	int data{};
	BinaryTree* left{};
	BinaryTree* right{};

public:
	BinaryTree(int data) : data(data) {}

	void add(vector<int> values, vector<char> direction) {
		assert(values.size() == direction.size());
		BinaryTree* current = this;
		// iterate on the path, create all necessary nodes
		for (int i = 0; i < (int)values.size(); ++i) {
			if (direction[i] == 'L') {
				if (!current->left)
					current->left = new BinaryTree(values[i]);
				else
					assert(current->left->data == values[i]);
				current = current->left;
			}
			else {
				if (!current->right)
					current->right = new BinaryTree(values[i]);
				else
					assert(current->right->data == values[i]);
				current = current->right;
			}
		}
	}

	void level_order_traversal() {
		queue<BinaryTree*> nodes_queue;
		nodes_queue.push(this);

		while (!nodes_queue.empty()) {
			int sz = nodes_queue.size();

			while (sz--) {
				BinaryTree* cur = nodes_queue.front();
				nodes_queue.pop();

				cout << cur->data << " ";
				if (cur->left)
					nodes_queue.push(cur->left);
				if (cur->right)
					nodes_queue.push(cur->right);
			}
			cout << "\n";
		}
	}

	void level_order_traversal_sorted() {
		priority_queue<pair<int, BinaryTree*>> nodes_queue[2];
		bool flag = 0;
		nodes_queue[flag].push({data, this});

		while (!nodes_queue[flag].empty()) {
			int sz = nodes_queue[flag].size();

			while (sz--) {
				BinaryTree* cur = nodes_queue[flag].top().second;
				nodes_queue[flag].pop();

				cout << cur->data << " ";

				if (cur->left)
					nodes_queue[!flag].push({cur->left->data, cur->left});
				if (cur->right)
					nodes_queue[!flag].push({ cur->right->data, cur->right });
			}
			flag = !flag;
			cout << "\n";
		}
	}

	void level_order_traversal_sorted_v2() {
		queue<BinaryTree*> nodes_queue;
		priority_queue<pair<int, BinaryTree*>> child_queue;
		nodes_queue.push(this);

		while (!nodes_queue.empty()) {
			int sz = nodes_queue.size();

			while (sz--) {
				BinaryTree* cur = nodes_queue.front();
				nodes_queue.pop();

				cout << cur->data << " ";

				if (cur->left)
					child_queue.push({ cur->left->data, cur->left });
				if (cur->right)
					child_queue.push({ cur->right->data, cur->right });
			}

			while (!child_queue.empty()) {
				nodes_queue.push(child_queue.top().second);
				child_queue.pop();
			}
			cout << "\n";
		}
	}

};

class PriorityQueue {
private:
	int capacity{1000};
	int* key{}; // Priority
	int* value{}; // values
	int size{};

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

	void heapify_up(int child_pos) {
		// stop when parent is smaller (or no parent)
		int par_pos = parent(child_pos);
		if (child_pos == 0 || key[par_pos] > key[child_pos])
			return;

		swap(key[child_pos], key[par_pos]);
		swap(value[child_pos], value[par_pos]);
		heapify_up(par_pos);
	}

	void heapify_down(int parent_pos) {	// O(logn)
		int child_pos = left(parent_pos);
		int right_child = right(parent_pos);

		if (child_pos == -1) // no children
			return;
		// is right bigger than left?
		if (right_child != -1 && key[right_child] > key[child_pos])
			child_pos = right_child;

		if (key[parent_pos] < key[child_pos]) {
			swap(key[parent_pos], key[child_pos]);
			swap(value[parent_pos], value[child_pos]);
			heapify_down(child_pos);
		}
	}

	void heapify() {	// O(n)
		for (int i = size / 2 - 1; i >= 0; --i)
			heapify_down(i);
	}

public:
	PriorityQueue() {
		key = new int[capacity] {};
		value = new int [capacity] {};
		size = 0;
	}

	~PriorityQueue() {
		delete[] key;
		delete[] value;
		key = value = nullptr;
	}

	void enqueue(int item, int priority) {
		assert(size + 1 <= capacity);
		key[size] = priority;
		value[size++] = item;
		heapify_up(size - 1);
	}

	void dequeue() {
		assert(!isempty());
		key[0] = key[--size];
		value[0] = value[size];
		heapify_down(0);
	}

	int top() {
		assert(!isempty());
		return value[0];
	}

	bool isempty() {
		return size == 0;
	}
};

class MaxHeap {
private:
	int capacity{1000};
	int* array{};
	int size{};

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

	void heapify_up(int child_pos) {
		// stop when parent is smaller (or no parent)
		int par_pos = parent(child_pos);
		if (child_pos == 0 || array[par_pos] > array[child_pos])
			return;

		swap(array[child_pos], array[par_pos]);
		heapify_up(par_pos);
	}

	void heapify_down(int parent_pos) {	// O(logn)
		int child_pos = left(parent_pos);
		int right_child = right(parent_pos);

		if (child_pos == -1) // no children
			return;
		// is right bigger than left?
		if (right_child != -1 && array[right_child] > array[child_pos])
			child_pos = right_child;

		if (array[parent_pos] < array[child_pos]) {
			swap(array[parent_pos], array[child_pos]);
			heapify_down(child_pos);
		}
	}

	void heapify() {	// O(n)
		for (int i = size / 2 - 1; i >= 0; --i)
			heapify_down(i);
	}

public:

	MaxHeap() {
		array = new int[capacity] {};
		size = 0;
	}

	MaxHeap(const vector<int>& v) {
		assert((int)v.size() <= capacity);
		array = new int[capacity] {};
		size = v.size();

		for (int i = 0; i < (int)v.size(); ++i)
			array[i] = v[i];

		heapify();
	}

	~MaxHeap() {
		delete[] array;
		array = nullptr;
	}

	int top() {
		assert(!isempty());
		return array[0];
	}

	void push(int key) {
		assert(size + 1 <= capacity);
		array[size++] = key;
		heapify_up(size - 1);
	}

	void pop() {
		assert(!isempty());
		array[0] = array[--size];
		heapify_down(0);
	}

	bool isempty() {
		return size == 0;
	}

	int sz() {
		return size;
	}
};

class KthNumberProcessor {
private:
	int k{};
	MaxHeap heap;

public:
	KthNumberProcessor(int k) : k(k) {}

	int next(int num) {
		if (heap.sz() < k)
			heap.push(num);
		else if (num < heap.top())
		{
			heap.pop();
			heap.push(num);
		}
		// else don't push as num > heap.top()
		return heap.top();
	}
};

void test_PriorityQueue() {
	PriorityQueue tasks;

	tasks.enqueue(1131, 1);
	tasks.enqueue(3111, 3);
	tasks.enqueue(2211, 2);
	tasks.enqueue(3161, 7);
	tasks.enqueue(7761, 7);

	cout << tasks.top() << "\n";
	tasks.dequeue();
	cout << tasks.top() << "\n";
	tasks.dequeue();

	tasks.enqueue(1535, 1);
	tasks.enqueue(2815, 2);
	tasks.enqueue(3845, 3);
	tasks.enqueue(3145, 3);

	while (!tasks.isempty()) {
		cout << tasks.top() << " ";
		tasks.dequeue();
	}
}

void test_binaryTree() {
	BinaryTree tree0(25);
	tree0.add({ 3, 5 }, { 'L', 'L' });
	tree0.add({ 7, 30 }, { 'R', 'L' });
	tree0.add({ 7, 6 }, { 'R', 'R' });

	tree0.level_order_traversal();
	cout << "\n";
	tree0.level_order_traversal_sorted();

	cout << "\n//////////////\n\n";
	BinaryTree tree(1);
	tree.add({ 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add({ 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add({ 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add({ 3, 6, 15 }, { 'R', 'R', 'L' });

	tree.add({ 2, 5, 13 }, { 'L', 'R', 'L' });
	tree.add({ 3, 6, 12 }, { 'R', 'R', 'R' });
	tree.add({ 3, 14, 15 }, { 'R', 'L', 'L' });
	tree.add({ 3, 14, 16 }, { 'R', 'L', 'R' });

	tree.level_order_traversal();
	cout << "\n";
	tree.level_order_traversal_sorted();
}

int main() {
	test_binaryTree();
}
