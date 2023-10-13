#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class BinarySearchTree {
private:
	int data{};
	BinarySearchTree* left{};
	BinarySearchTree* right{};
	BinarySearchTree* parent{};

	// Modified search: Return chain of ancestors from node to target
	bool find_chain(vector<BinarySearchTree*>& ancestors, int target) {
		ancestors.push_back(this);

		if (target == data)
			return true;

		if (target < data)
			return left && left->find_chain(ancestors, target);

		return right && right->find_chain(ancestors, target);
	}

	BinarySearchTree* find(int target) {
		if (target == data)
			return this;

		if (target < data) {
			if (!left)
				return nullptr;
			return left->find(target);
		}

		if (!right)
			return nullptr;
		return right->find(target);
	}
public:

	BinarySearchTree(int data, BinarySearchTree* parent = nullptr) : data(data), parent(parent) {}

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

	void insert_v2(int target) {
		if (target < data) {
			if (!left)
				left = new BinarySearchTree(target, this);
			else
				left->insert_v2(target);
		}
		else if (target > data) {
			if (!right)
				right = new BinarySearchTree(target, this);
			else
				right->insert_v2(target);
		} // else: exists already
	}

	bool search(int target) {	// tail recursion
		if (target == data)
			return true;

		if (target < data)
			return left && left->search(target);

		return right && right->search(target);
	}

	int min_value() {
		BinarySearchTree* cur = this;
		while (cur && cur->left)
			cur = cur->left;

		return cur->data;
	}

	BinarySearchTree* get_next(vector<BinarySearchTree*>& ancestors) {
		if (ancestors.size() == 0)
			return nullptr;

		BinarySearchTree* node = ancestors.back();	// last element
		ancestors.pop_back();

		return node;
	}
	pair<bool, int> successor(int target) {
		vector<BinarySearchTree*> ancestors;

		if (!find_chain(ancestors, target))	// not exist
			return make_pair(false, -1);

		BinarySearchTree* child = get_next(ancestors);

		if (child->right)	// must have be in min of right
			return make_pair(true, child->right->min_value());

		BinarySearchTree* parent = get_next(ancestors);

		// Cancel chain of ancestors I am BIGGER than them
		while (parent && parent->right == child)
			child = parent, parent = get_next(ancestors);

		if (parent)
			return make_pair(true, parent->data);
		return make_pair(false, -1);
	}

	pair<bool, int> successor_v2(int target) {
		BinarySearchTree* child = find(target);

		if (!child)	// not exist
			return make_pair(false, -1);

		if (child->right)	// must have be in min of right
			return make_pair(true, child->right->min_value());

		BinarySearchTree* parent = child->parent;

		while (parent && parent->right == child)
			child = parent, parent = child->parent;

		if (parent)
			return make_pair(true, parent->data);
		return make_pair(false, -1);
	}

	int search_successor(int target, int parent) {
		int child = target;

		if (child == data) {

			if (right)
				return right->min_value();
			else
				return parent;
		}

		if (child < data) {
			if (left) {
				parent = data;
				return left->search_successor(child, parent);
			}
			return -1;
		}

		if (!right)
			return -1;
		return right->search_successor(child, parent);
	}
	deque<int> successor_queries_v2(deque<int> dq) {
		for (int i = 0; i < dq.size(); i++)
			dq[i] = search_successor(dq[i], -1);

		return dq;
	}

	void successor_queries(deque<int>& queries, vector<int>& answer, vector<int>& traversal) {
		if (queries.empty())
			return;

		if (left && queries.front() < data) {
			left->successor_queries(queries, answer, traversal);

			if (queries.empty())
				return;
		}

		// If the last element added in the traversal is the requested element
		// Then the current element is its successor! Catch it! That simple!
		if (!traversal.empty() && traversal.back() == queries.front()) {
			answer.push_back(data);
			queries.pop_front();

			if (queries.empty())
				return;
		}
		traversal.push_back(data);

		// Observe the = : If target equal the cur data and we have right, then successor on right
		// Trace the root (e.g. 50)
		if (right && queries.front() >= data)
			right->successor_queries(queries, answer, traversal);
	}
};

bool is_degenerate(vector<int>& preorder) {
	// other IMPORTANT approach:
	// https://www.udemy.com/course/dscpp-skills/learn/lecture/26862010#overview
	// same idea diffrent implementation:
	// https://www.geeksforgeeks.org/check-if-each-internal-node-of-a-bst-has-exactly-one-child/

	for (int i = 0; i < preorder.size() - 1; i++)
	{
		if ((preorder[i] > preorder[i + 1] && preorder[i] < preorder[preorder.size() - 1]) ||
			(preorder[i] < preorder[i + 1] && preorder[i] > preorder[preorder.size() - 1]))
			return false;
	}
	return true;
}

int main() {
	//BinarySearchTree tree(50);
	//tree.insert_v2(20);
	//tree.insert_v2(45);
	//tree.insert_v2(70);
	//tree.insert_v2(73);
	//tree.insert_v2(35);
	//tree.insert_v2(15);
	//tree.insert_v2(60);

	//tree.print_inorder();

	//vector<int> v { 15, 20, 35, 45, 50, 60, 70, 73, 100 }; // 100 isn't in the tree
	//for (int i = 0; i < v.size(); i++)
	//{
	//	cout << v[i] << " ";
	//	pair<bool, int> p = tree.successor_v2(v[i]);

	//	if (p.first)
	//		cout << p.second << "\n";
	//	else
	//		cout << "NA\n";
	//}

	/*vector<int> vec { 500, 400, 300, 200, 250, 275, 260, 280 };
	cout << is_degenerate(vec); // NO*/

	BinarySearchTree tree(5);
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);
	tree.insert(8);
	tree.insert(9);

	tree.level_order_traversal2();

	deque<int> dq {1, 4, 9}; // 2, 5, -1
	dq = tree.successor_queries_v2(dq);
	for (int i = 0; i < dq.size(); i++)
		cout << dq[i] << " ";
}