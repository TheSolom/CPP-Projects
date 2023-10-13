#include <iostream>
#include <vector>
using namespace std;

class trie {
private:
	static const int MAX_CHAR = 26;
	trie* child[MAX_CHAR]{};
	bool isLeaf{};

public:
	void insert(string str) {
		trie* cur = this;

		for (int i = 0; i < (int)str.size(); i++) {
			int idx = str[i] - 'a';
			if (!cur->child[idx])
				cur->child[idx] = new trie();

			cur = cur->child[idx];
		}
		cur->isLeaf = true;
	}

	// O(NL) where N number of words and L is word length
	void get_all_strings(vector<string>& res, string s = "") {
		if (isLeaf)
			res.push_back(s);

		for (int i = 0; i < MAX_CHAR; i++) {
			if (child[i])
				child[i]->get_all_strings(res, s + (char)(i + 'a'));
		}
	}

	void auto_complete(const string& str, vector<string>& res, int idx = 0) {
		trie* cur = this;

		for (int i = 0; i < (int)str.size(); i++) {
			int idx = str[i] - 'a';
			if (!cur->child[idx])
				return;

			cur = cur->child[idx];
		}

		cur->get_all_strings(res, str);
	}

	bool word_exist(string str) {
		// If recursive: Time Limit Exceeded on leetcode
		trie* cur = this;

		for (int idx = 0; idx < (int)str.size(); ++idx) {
			int ch = str[idx] - 'a';
			if (!cur->child[ch])
				return false;

			cur = cur->child[ch];
		}
		return cur->isLeaf;
	}
	// https://leetcode.com/problems/implement-magic-dictionary/
	bool word_exist_with_1_change(string str) {
		// Brute force all possible 1-char change and search for it  O(L * 26 * L)
		for (int i = 0; i < (int)str.size(); i++) {
			char cpy = str[i];
			for (char ch = 'a'; ch <= 'z'; ch++)
			{
				if (ch != cpy) 
				{
					str[i] = ch;
					if (word_exist(str))
						return true;
				}
			}
			str[i] = cpy;	// copy back
		}
		return false;
	}
};

class MagicDictionary {
public:
	trie tree;

	void buildDict(vector<string> dictionary) {
		for (int i = 0; i < (int)dictionary.size(); i++)
			tree.insert(dictionary[i]);
	}

	bool search(string searchWord) {
		return tree.word_exist_with_1_change(searchWord);
	}
};

int main() {
	MagicDictionary magicDictionary;

	magicDictionary.buildDict({ "hello", "leetcode" });

	cout << magicDictionary.search("hello");	 // False
	cout << magicDictionary.search("hhllo");	 // True, We can change the second 'h' to 'e' to match "hello"
	cout << magicDictionary.search("hell");      // False
	cout << magicDictionary.search("leetcoded"); // False
}
