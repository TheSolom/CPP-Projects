#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class AVLTree {
private:
	struct BinaryNode {
		int data{};
		int height{};
		int count{ 1 };
		BinaryNode* left{};
		BinaryNode* right{};

		BinaryNode(int data) : data(data) {}

		int ch_height(BinaryNode* node) {	// child height
			if (!node)
				return -1;			// -1 for null
			return node->height;	// 0 for leaf
		}
		int ch_count(BinaryNode* node) {	// child count
			if (!node)
				return 0;			// 0 for null
			return node->count;	// 1 for leaf
		}
		int balance_factor() {
			return ch_height(left) - ch_height(right);
		}
		void update() {	// call in end of insert function
			height = 1 + max(ch_height(left), ch_height(right));
			count = 1 + ch_count(left) + ch_count(right);
		}
	};

	BinaryNode* root{};

	BinaryNode* right_rotation(BinaryNode* Q) {
		BinaryNode* P = Q->left;
		Q->left = P->right;
		P->right = Q;
		Q->update();
		P->update();
		return P;
	}

	BinaryNode* left_rotation(BinaryNode* P) {
		BinaryNode* Q = P->right;
		P->right = Q->left;
		Q->left = P;
		P->update();
		Q->update();
		return Q;
	}

	BinaryNode* balance(BinaryNode* node) {
		if (node->balance_factor() == 2) { 			// Left
			if (node->left->balance_factor() == -1)	// Left Right?
				node->left = left_rotation(node->left);	// To Left Left

			node = right_rotation(node);	// Balance Left Left
		}
		else if (node->balance_factor() == -2) {
			if (node->right->balance_factor() == 1)
				node->right = right_rotation(node->right);

			node = left_rotation(node);
		}
		return node;
	}

	BinaryNode* insert_node(int target, BinaryNode* node) {
		if (target < node->data) {
			if (!node->left)
				node->left = new BinaryNode(target);
			else
				// change left. update left as it might be balanced
				node->left = insert_node(target, node->left);
		}
		else if (target > node->data) {
			if (!node->right)
				node->right = new BinaryNode(target);
			else
				node->right = insert_node(target, node->right);
		}
		node->update();
		return balance(node);
	}

	BinaryNode* min_node(BinaryNode* cur) {
		while (cur && cur->left)
			cur = cur->left;
		return cur;
	}

	BinaryNode* delete_node(int target, BinaryNode* node) {
		if (!node)
			return nullptr;

		if (target < node->data)
			node->left = delete_node(target, node->left);
		else if (target > node->data)
			node->right = delete_node(target, node->right);
		else {
			BinaryNode* tmp = node;

			if (!node->left && !node->right)	// case 1: no child
				node = nullptr;
			else if (!node->right) 	// case 2: has left only
				node = node->left;		// connect with child
			else if (!node->left)	// case 2: has right only
				node = node->right;
			else {	// 2 children: Use successor
				BinaryNode* mn = min_node(node->right);
				node->data = mn->data;	// copy & go delete
				node->right = delete_node(node->data, node->right);
				tmp = nullptr;	// Don't delete me. Successor will be deleted
			}
			if (tmp)
				delete tmp;
		}
		if (node) {
			node->update();
			node = balance(node);
		}
		return node;
	}

	bool search(int target, BinaryNode* node) {
		if (!node)
			return false;

		if (target == node->data)
			return true;

		if (target < node->data)
			return search(target, node->left);

		return search(target, node->right);
	}

	BinaryNode* lower_bound(int target, BinaryNode* node) {
		if (!node)
			return nullptr;

		if (target <= node->data) {
			// Can we find tighter answer in the left?
			BinaryNode* ans = lower_bound(target, node->left);
			if (ans)
				return ans;
			return node;
		}

		return lower_bound(target, node->right);
	}

	BinaryNode* upper_bound(int target, BinaryNode* node) {
		if (!node)
			return nullptr;

		if (target < node->data) {
			// Can we find tighter answer in the left?
			BinaryNode* ans = upper_bound(target, node->left);
			if (ans)
				return ans;
			return node;
		}
		return upper_bound(target, node->right);
	}

	// if left => count parents and their right successors also the node's right side successors
	// if right => count root and it's right successors also the node's right side successors
	int all_upper_bounds_count_v1(int target, BinaryNode* node) { // O(n)
		int sum = 0;

		if (!node)
			return sum;

		if (target < node->data)
			sum++;

		sum += all_upper_bounds_count_v1(target, node->left);
		sum += all_upper_bounds_count_v1(target, node->right);
	}

	int all_upper_bounds_count_v2(int target, BinaryNode* node) { // O(logn)
		if (!node)
			return 0;

		if (target < node->data) {
			int sum = 1;
			if (node->right)
				sum += node->right->count;

			return sum + all_upper_bounds_count_v2(target, node->left);
		}

		return all_upper_bounds_count_v2(target, node->right);
	}

public:
	void insert_value(int target) {
		if (!root)
			root = new BinaryNode(target);
		else
			root = insert_node(target, root);
	}

	void delete_value(int target) {
		if (root)
			root = delete_node(target, root);
		else
			cout << "Tree is empty!";
	}

	pair<bool, int> lower_bound(int target) {
		if (root) {
			BinaryNode* lb = lower_bound(target, root);
			if (!lb)
				return make_pair(false, -1);

			return make_pair(true, lb->data);
		}
		else
			return make_pair(false, -2);
	}

	pair<bool, int> upper_bound(int target) {
		if (root) {
			BinaryNode* up = upper_bound(target, root);
			if (!up)
				return make_pair(false, -1);

			return make_pair(true, up->data);
		}
		else
			return make_pair(false, -2);
	}

	int count_inversion(const vector<int>& vec) {	// O(nlogn) 
		int count = 0;
		for (int i = 0; i < vec.size(); ++i) {
			insert_value(vec[i]);
			count += all_upper_bounds_count_v2(vec[i], root);
		}

		return count;
	}
};

class PriorityQueue {
private:
	struct BinaryNode {
		int priority{};
		vector<int> task_ids{};
		int height{};
		BinaryNode* left{};
		BinaryNode* right{};

		BinaryNode(int task_id, int task_priority) : priority(task_priority) {
			task_ids.push_back(task_id);
		}

		int ch_height(BinaryNode* node) {	// child height
			if (!node)
				return -1;			// -1 for null
			return node->height;	// 0 for leaf
		}
		int balance_factor() {
			return ch_height(left) - ch_height(right);
		}
		void update_height() {	// call in end of insert function
			height = 1 + max(ch_height(left), ch_height(right));
		}
	};

	BinaryNode* root{};

	BinaryNode* right_rotation(BinaryNode* Q) {
		BinaryNode* P = Q->left;
		Q->left = P->right;
		P->right = Q;
		Q->update_height();
		P->update_height();
		return P;
	}

	BinaryNode* left_rotation(BinaryNode* P) {
		BinaryNode* Q = P->right;
		P->right = Q->left;
		Q->left = P;
		P->update_height();
		Q->update_height();
		return Q;
	}

	BinaryNode* balance(BinaryNode* node) {
		if (node->balance_factor() == 2) { 			// Left
			if (node->left->balance_factor() == -1)	// Left Right?
				node->left = left_rotation(node->left);	// To Left Left

			node = right_rotation(node);	// Balance Left Left
		}
		else if (node->balance_factor() == -2) {
			if (node->right->balance_factor() == 1)
				node->right = right_rotation(node->right);

			node = left_rotation(node);
		}

		return node;
	}

	BinaryNode* insert_node(int task_id, int task_priority, BinaryNode* node) {
		if (task_priority < node->priority) {
			if (!node->left)
				node->left = new BinaryNode(task_id, task_priority);
			else
				// change left. update left as it might be balanced
				node->left = insert_node(task_id, task_priority, node->left);
		}
		else if (task_priority > node->priority) {
			if (!node->right)
				node->right = new BinaryNode(task_id, task_priority);
			else
				node->right = insert_node(task_id, task_priority, node->right);
		}
		else
			node->task_ids.push_back(task_id); // existing key

		node->update_height();
		return balance(node);
	}

	BinaryNode* min_node(BinaryNode* cur) {
		while (cur && cur->left)
			cur = cur->left;
		return cur;
	}

	BinaryNode* max_node(BinaryNode* cur) {
		while (cur && cur->right)
			cur = cur->right;
		return cur;
	}

	BinaryNode* delete_node(int task_priority, BinaryNode* node) {
		if (!node)
			return nullptr;

		if (task_priority < node->priority)
			node->left = delete_node(task_priority, node->left);
		else if (task_priority > node->priority)
			node->right = delete_node(task_priority, node->right);
		else {
			BinaryNode* tmp = node;

			if (!node->left && !node->right)	// case 1: no child
				node = nullptr;
			else if (!node->right) 	// case 2: has left only
				node = node->left;		// connect with child
			else if (!node->left)	// case 2: has right only
				node = node->right;
			else {	// 2 children: Use successor
				BinaryNode* mn = min_node(node->right);
				node->priority = mn->priority;	// copy & go delete
				node->right = delete_node(node->priority, node->right);
				tmp = nullptr;	// Don't delete me. Successor will be deleted
			}
			if (tmp)
				delete tmp;
		}
		if (node) {
			node->update_height();
			node = balance(node);
		}

		return node;
	}

public:
	void enqueue(int task_id, int task_priority) {
		if (!root)
			root = new BinaryNode(task_id, task_priority);
		else
			root = insert_node(task_id, task_priority, root);
	}

	int dequeue() {
		if (!isEmpty())
		{
			BinaryNode* mx = max_node(root);
			int dequeued_value{ -1 };

			if (mx->task_ids.size() > 0) {
				dequeued_value = mx->task_ids.back();
				mx->task_ids.pop_back();
			}
			if (mx->task_ids.size() == 0)
				root = delete_node(mx->priority, root);

			return dequeued_value;
		}
		else
			cout << "Empty queue\n";
	}

	bool isEmpty() {
		return root == nullptr;
	}
};

void test_PriorityQueue() {
	PriorityQueue tasks;

	tasks.enqueue(1131, 1);
	tasks.enqueue(3111, 3);
	tasks.enqueue(2211, 2);
	tasks.enqueue(3161, 3);
	tasks.enqueue(7761, 7);

	cout << tasks.dequeue() << "\n";	// 7761
	cout << tasks.dequeue() << "\n";	// 3161

	tasks.enqueue(1535, 1);
	tasks.enqueue(2815, 2);
	tasks.enqueue(3845, 3);
	tasks.enqueue(3145, 3);

	// 3145 3845 3111 2815 2211 1535 1131
	while (!tasks.isEmpty())
		cout << tasks.dequeue() << " ";
}

class AVLTree_string_dictionary {
private:
	struct BinaryNode {
		string data{ };
		bool is_full_word{};
		int height{ };
		BinaryNode* left{ };
		BinaryNode* right{ };

		BinaryNode(string data, bool is_full_word) :
			data(data), is_full_word(is_full_word) {
		}

		int ch_height(BinaryNode* node) {	// child height
			if (!node)
				return -1;			// -1 for null
			return node->height;	// 0 for leaf
		}
		int update_height() {	// call in end of insert function
			return height = 1 + max(ch_height(left), ch_height(right));
		}
		int balance_factor() {
			return ch_height(left) - ch_height(right);
		}
	};

	BinaryNode* root{ };

	///////////////////////////
	BinaryNode* right_rotation(BinaryNode* Q) {
		BinaryNode* P = Q->left;
		Q->left = P->right;
		P->right = Q;
		Q->update_height();
		P->update_height();
		return P;
	}

	BinaryNode* left_rotation(BinaryNode* P) {
		BinaryNode* Q = P->right;
		P->right = Q->left;
		Q->left = P;
		P->update_height();
		Q->update_height();
		return Q;
	}

	BinaryNode* balance(BinaryNode* node) {
		if (node->balance_factor() == 2) { 			// Left
			if (node->left->balance_factor() == -1)	// Left Right?
				node->left = left_rotation(node->left);	// To Left Left

			node = right_rotation(node);	// Balance Left Left
		}
		else if (node->balance_factor() == -2) {
			if (node->right->balance_factor() == 1)
				node->right = right_rotation(node->right);

			node = left_rotation(node);
		}
		return node;
	}

	// -1 (not exist), 0 exist as prefix, 1 exist as full word
	int search(string target, BinaryNode* node) {
		if (!node)
			return -1;

		if (target == node->data)
			return node->is_full_word;

		if (target < node->data)
			return search(target, node->left);

		return search(target, node->right);
	}

	BinaryNode* insert_node(string target, bool is_full_word, BinaryNode* node) {
		if (target < node->data) {
			if (!node->left)
				node->left = new BinaryNode(target, is_full_word);
			else	// change left. update left as it might be balanced
				node->left = insert_node(target, is_full_word, node->left);
		}
		else if (target > node->data) {
			if (!node->right)
				node->right = new BinaryNode(target, is_full_word);
			else
				node->right = insert_node(target, is_full_word, node->right);
		}
		else if (is_full_word)	// if existed before but this is full_word, mark it
			node->is_full_word = 1;
		node->update_height();
		return balance(node);
	}

	void insert_value(string target, int is_full_word) {
		if (!root)
			root = new BinaryNode(target, is_full_word);
		else
			root = insert_node(target, is_full_word, root);
	}

public:
	void insert_string(string target) {	// O(nlogn)
		// Idea is to insert all the possible prefixes and add to AVL
		// Mark which is prefix and which is full word
		if (target == "")
			return;

		string cur;
		for (int i = 0; i < (int)target.size(); ++i) {
			cur += target[i];
			// If it is last index, then this is the original full word
			insert_value(cur, i == (int)target.size() - 1);
		}
	}

	bool word_exist(string target) {
		return search(target, root) == 1;
	}

	bool prefix_exist(string target) {
		// if exists as full or prefix
		return search(target, root) != -1;
	}
};

void test_string_dictionary() {
	AVLTree_string_dictionary tree;

	tree.insert_string("abcd");
	tree.insert_string("xyz");

	cout << tree.word_exist("abcd") << "\n";		// 1
	cout << tree.word_exist("ab") << "\n";		// 0
	cout << tree.prefix_exist("ab") << "\n";		// 1

	tree.insert_string("ab");

	cout << tree.word_exist("ab") << "\n";		// 1
	cout << tree.word_exist("cd") << "\n";		// 0
	cout << tree.word_exist("abcde") << "\n";		// 0
}

int main()
{
	test_string_dictionary();
}