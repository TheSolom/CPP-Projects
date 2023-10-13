#include<iostream>
#include<map>
#include <unordered_map>
using namespace std;

class trie {
private:
	static const int MAX_CHAR = 26;
	trie* child[MAX_CHAR]{};
	bool isLeaf{};

public:
	trie() {}

	void insert(string str, int idx = 0) {
		if (idx == (int)str.size())
			isLeaf = 1;
		else {
			int cur = str[idx] - 'a';
			if (child[cur] == 0)
				child[cur] = new trie();

			child[cur]->insert(str, idx + 1);
		}
	}
	void insert_iterative(string str) {
		trie* cur = this;

		for (int i = 0; i < (int)str.size(); i++)
		{
			int idx = str[i] - 'a';
			if (!cur->child[idx])
				cur->child[idx] = new trie();

			cur = cur->child[idx];
		}
		cur->isLeaf = true;
	}

	void insert_suffix(string str, int idx = 0) {
		trie* cur = this;

		for (int i = (int)str.size() - 1; i >= 0; i--)
		{
			int idx = str[i] - 'a';
			if (!cur->child[idx])
				cur->child[idx] = new trie();

			cur = cur->child[idx];
		}
		cur->isLeaf = true;
	}

	bool word_exist(string str, int idx = 0) {
		if (idx == (int)str.size())
			return isLeaf;	// there is a string marked here

		int cur = str[idx] - 'a';
		if (!child[cur])
			return false;	// such path don't exist

		return child[cur]->word_exist(str, idx + 1);
	}
	bool word_exist_iterative(string str) {
		trie* cur = this;

		for (int i = 0; i < (int)str.length(); i++)
		{
			int idx = str[i] - 'a';
			if (!cur->child[idx])
				return false;

			cur = cur->child[idx];
		}
		return cur->isLeaf;
	}

	bool prefix_exist(string str, int idx = 0) {
		if (idx == (int)str.size())
			return true;	// all subword covered

		int cur = str[idx] - 'a';
		if (!child[cur])
			return false;	// such path don't exist

		return child[cur]->prefix_exist(str, idx + 1);
	}
	bool prefix_exist_iterative(string str) {
		trie* cur = this;

		for (int i = 0; i < (int)str.length(); i++)
		{
			int idx = str[i] - 'a';
			if (!cur->child[idx])
				return false;

			cur = cur->child[idx];
		}
		return true;
	}

	bool suffix_exist(string str) {
		trie* cur = this;

		for (int i = (int)str.size() - 1; i >= 0; i--)
		{
			int idx = str[i] - 'a';
			if (!cur->child[idx])
				return false;
			cur = cur->child[idx];
		}
		return true;
	}

	string first_word_prefix(const string& str) {
		trie* cur = this;

		for (int i = 0; i < (int)str.length(); i++)
		{
			int idx = str[i] - 'a';
			if (!cur->child[idx])
				break;
			// Does this child marked as word? we found a prefix that is a word
			if (cur->child[idx]->isLeaf)
				return str.substr(0, i + 1);

			cur = cur->child[idx];
		}
		return str;
	}
};

class trie_map {
private:
	map<int, trie_map*> child;	// based on self-balancing BST, so keys are sorted (which is logn), which usually not important
	//unordered_map<int, trie*> child;  // This is based on hashing, O(1), but keys are not sorted
	bool isLeaf{};

public:
	trie_map() {}

	void insert(string str) {
		trie_map* cur = this;

		for (int i = 0; i < (int)str.size(); i++) {
			int idx = str[i] - 'a';
			if (!cur->child.count(idx))
				cur->child[idx] = new trie_map();

			cur = cur->child[idx];
		}
		cur->isLeaf = true;
	}

	bool word_exist(string str) {
		trie_map* cur = this;

		for (int i = 0; i < (int)str.size(); i++) {
			int idx = str[i] - 'a';
			if (!cur->child.count(idx))
				return false;	// such path don't exist

			cur = cur->child[idx];
		}
		return cur->isLeaf;
	}
};

class trie_string {
private:
	// The major change: instead of letter on edge, it will be a string
	map<string, trie_string*> child;
	bool isLeaf{};

public:
	trie_string() {}

	void insert(const vector<string>& path) {
		trie_string* cur = this;

		for (int idx = 0; idx < (int)path.size(); ++idx) {
			if (!cur->child.count(path[idx]))
				cur->child[path[idx]] = new trie_string();

			cur = cur->child[path[idx]];
		}
		cur->isLeaf = true;
	}

	bool subpath_exist(const vector<string>& path) {
		trie_string* cur = this;

		for (int idx = 0; idx < (int)path.size(); ++idx) {
			if (!cur->child.count(path[idx]))
				return false;

			cur = cur->child[path[idx]];
		}
		return true;
	}
};

int main() {
	trie_string tree;

	vector<string> path;

	path = { "home", "software", "eclipse" };
	tree.insert(path);
	path = { "home", "software", "eclipse", "bin" };
	tree.insert(path);
	path = { "home", "installed", "gnu" };
	tree.insert(path);
	path = { "user", "mostafa", "tmp" };
	tree.insert(path);
	path = { "user", "mostafa", "tmp" };
	cout << tree.subpath_exist(path) << "\n"; // 1
	path = { "user", "mostafa" };
	cout << tree.subpath_exist(path) << "\n"; // 1
	path = { "user", "mostafa", "private" };
	cout << tree.subpath_exist(path) << "\n"; // 0
}
