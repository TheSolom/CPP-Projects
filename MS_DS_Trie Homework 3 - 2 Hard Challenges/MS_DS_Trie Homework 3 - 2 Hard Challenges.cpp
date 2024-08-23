#include <iostream>
#include <vector>
#include <set>
using namespace std;

class trie {
private:
	static const int MAX_CHAR = 27;
	trie* child[MAX_CHAR]{};
	bool isLeaf{};
	int index{ -1 };

public:
	void insert(const string& str, int starting_pos = 0) {
		trie* cur = this;

		for (int i = starting_pos; i < (int)str.size(); i++) {
			int idx = str[i] - 'a';
			if (!cur->child[idx])
				cur->child[idx] = new trie();

			cur = cur->child[idx];
		}
		cur->isLeaf = true;
	}

	void insert_v2(const string& str, int word_idx) {
		trie* cur = this;

		for (int idx = 0; idx < (int)str.size(); idx++) {
			int ch = str[idx] - 'a';
			if (!cur->child[ch])
				cur->child[ch] = new trie();

			if (cur->child[ch]->index == -1)
				cur->child[ch]->index = word_idx;

			cur = cur->child[ch];
		}
	}

	bool prefix_exist(string str) {
		trie* cur = this;

		for (int i = 0; i < (int)str.size(); i++) {
			int idx = str[i] - 'a';
			if (!cur->child[idx])
				return false;

			cur = cur->child[idx];
		}
		return true;
	}

	void print_all_matches(const string& str, int starting_pos = 0) {
		trie* cur = this;

		for (int i = starting_pos; i < (int)str.size(); i++) {
			int idx = str[i] - 'a';
			if (!cur->child[idx])
				return;

			cur = cur->child[idx];

			if (cur->isLeaf)
				cout << str.substr(starting_pos, i - starting_pos + 1) << "\n";
		}
	}

	int get_positions(const string& str) {
		trie* cur = this;

		for (int idx = 0; idx < (int)str.size(); idx++) {
			int ch = str[idx] - 'a';
			if (!cur->child[ch])
				return -1;

			cur = cur->child[ch];
		}
		return cur->index;
	}
};

void list_substrs(const string& str, vector<string>& queries) { // O(S^2 + QL)
	trie tree;
	// Generate all suffixes and add 
	// // O(S^2): S string length
	for (int i = 0; i < (int)str.size() - 1; i++)
		tree.insert(str, i);	// suffix starting at i

	// O(QL): queries * string length
	for (const string& query : queries)
		if (tree.prefix_exist(query))
			cout << query << "\n";
}
/* Reverse thinking using trie.
 * - Add the queries themselves to the trie
 * - For the string, generate all its suffixes
 * - For each suffix, iterave over the trie and print all words you meet.
 * These words are prefixes of this suffix ==> are sub-strings from original string
 */
void list_substrs_V2(const string& str, vector<string>& queries) { // O(QL + SL) vs prev O(QL + SS)
	trie tree;

	for (int i = 0; i < (int)queries.size(); i++) // O(QL)
		tree.insert(queries[i]);

	// O(SL): observe, we won't iterate in the tree MORE than L steps
	for (int i = 0; i < (int)str.size() - 1; i++)
		tree.print_all_matches(str, i);
}

class WordFilter {
// https://leetcode.com/problems/prefix-and-suffix-search
public:
	trie tree;

	WordFilter(vector<string>& words) {
		set<string> words_set;

		// Generate all pairs of suffix/prefix
		// But, trie already generate all prefixes, so generate suffixes + one prefix
		// Use unique symbol to differentiate suffix from prefix (otherwise a word is unclear)
		// As we create more words (n^2), this solution needs more memory
		// But it queries in faster time!
		for (int i = (int)words.size() - 1; i >= 0; i--) {
			if (words_set.insert(words[i]).second) {

				string suffix;
				for (int j = (int)words[i].size() - 1; j >= 0; j--) {
					suffix = words[i][j] + suffix;
					string new_word = suffix + "{" + words[i];
					tree.insert_v2(new_word, i);
				}
			}
		}
	}

	int f(string prefix, string suffix) {
		string new_word = suffix + "{" + prefix;
		return tree.get_positions(new_word);
	}
};

int main()
{
	vector<string> vec{ "abbba","abba" };
	WordFilter filter(vec);
	cout << filter.f("ab", "ba") << "\n";
}
