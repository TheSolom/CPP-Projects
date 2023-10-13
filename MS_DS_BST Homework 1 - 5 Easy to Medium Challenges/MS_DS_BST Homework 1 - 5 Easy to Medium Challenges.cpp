#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class BinarySearchTree {
private:
	int data{};
	BinarySearchTree* left{};
	BinarySearchTree* right{};

public:
	BinarySearchTree(int data, BinarySearchTree* left = nullptr, BinarySearchTree* right = nullptr) :
		data(data), left(left), right(right) {}

	void print_inorder() {
		if (left)
			left->print_inorder();

		cout << data << " ";

		if (right)
			right->print_inorder();
	}

	void level_order_traversal2() {
		queue<BinarySearchTree*> nodes_queue;
		nodes_queue.push(this);

		int level = 0;
		while (!nodes_queue.empty()) {
			int sz = nodes_queue.size();

			cout << "Level " << level << ": ";
			while (sz--) {
				BinarySearchTree* cur = nodes_queue.front();
				nodes_queue.pop();

				cout << cur->data << " ";
				if (cur->left)
					nodes_queue.push(cur->left);
				if (cur->right)
					nodes_queue.push(cur->right);
			}
			level++;
			cout << "\n";
		}
	}

	void insert(int target) {
		if (target < data) {
			if (!left)
				left = new BinarySearchTree(target);
			else
				left->insert(target);
		}
		else if (target > data) {
			if (!right)
				right = new BinarySearchTree(target);
			else
				right->insert(target);
		} // else: exists already
	}

	bool search(int target) {	// tail recursion
		if (target == data)
			return true;

		if (target < data)
			return left && left->search(target);

		return right && right->search(target);
	}

	bool search_iterative(int target) {
		BinarySearchTree* cur = this;

		while (cur)
		{
			if (target == cur->data)
				return true;

			if (target < data && left)
				cur = cur->left;
			else if (right)
				cur = cur->right;
		}
		return false;
	}

	void insert_not_bst(int left_, int left_right) {
		left = new BinarySearchTree(left_);
		left->right = new BinarySearchTree(left_right);
	}

	bool is_bst_util(BinarySearchTree* cur, int init_min, int init_max) {
		// https://leetcode.com/problems/validate-binary-search-tree
		if (!cur)
			return true;

		if (cur->data < init_min || cur->data > init_max)
			return false;

		return is_bst_util(cur->left, init_min, cur->data) && is_bst_util(cur->right, cur->data, init_max);
	}
	bool is_bst() {
		return is_bst_util(this, INT_MIN, INT_MAX);
	}

	void get_inorder(vector<int>& values) {
		if (left)
			left->get_inorder(values);

		values.push_back(data);

		if (right)
			right->get_inorder(values);
	}
	bool is_bst2() {
		// Check inorder traversal is sorted (and unique)!
		vector<int> values;
		get_inorder(values);

		for (int i = 1; i < (int)values.size(); i++) {
			if (values[i] < values[i - 1])
				return false;
		}
		return true;
	}

	int kth_smallest(int& k) {
		if (left) {
			int lres = left->kth_smallest(k);
			if (k == 0)
				return lres;
		}

		--k;
		if (k == 0)
			return data;

		if (right)
			return right->kth_smallest(k);

		return -1234;
	}

	vector<int> path(vector<int>& vec, int target) {
		if (target == data)
			return vec;
		else
			vec.push_back(data);

		if (target < data && left)
			return left->path(vec, target);
		else if (right)
			return right->path(vec, target);
	}

	int Lowest_Common_Ancestor(int x, int y) {
		// if both on left or right subtree, then lca must be in the subtree
		// otherwise this node is lca: x is in a branch and y in another
		if (x < data && y < data)
			return left->Lowest_Common_Ancestor(x, y);

		if (x > data && y > data)
			return right->Lowest_Common_Ancestor(x, y);

		return data;
	}
};

BinarySearchTree* build_bst(vector<int>& values, int start = 0, int end = -10) {
	if (end == -10)
		end = (int)values.size() - 1;

	if (start > end)
		return nullptr;

	int mid = (start + end) / 2;
	BinarySearchTree* left = build_bst(values, start, mid - 1);
	BinarySearchTree* right = build_bst(values, mid + 1, end);
	BinarySearchTree* root = new BinarySearchTree(values[mid], left, right);

	return root;
}

int main() {
	BinarySearchTree tree(4);
	tree.insert(0);
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(7);
	tree.insert(8);
	tree.insert(9);

	/*tree.print_inorder();
	cout << "\n";
	for (int i = 0; i <= 12; i++) { // k (1-based)
		int k = i;
		cout << tree.kth_smallest(k) << " ";
	}*/

	/*tree.insert_not_bst(20, 55);
	tree.is_bst();*/

	/*vector <int> vec { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	BinarySearchTree* tree = build_bst(vec);*/
	
}