#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int count_unique_substrings(const string& str) {
	// O(L^3)
	// Try all possible substrings (L^2) and insert in hashset
	// Hashing a string is typically O(L)
	unordered_set<string> set;
	// List all substrings and add to the set
	for (int i = 0; i < (int)str.size(); i++)
		for (int j = i; j < (int)str.size(); j++) 
			set.insert(str.substr(i, j - i + 1));

	return set.size();	// unique elements
	// Note: Using a trie: we can efficiently solve it in O(L^2)
	// Don't create the string and add to trie
	// For every stating position: let the second loop keep inserting
	// In trie letter by letter and mark as leaf
	// Hence overall only 2 loops
}

int count_substrings_match(const string& str1, const string& str2) {
	// Add all substrings
	unordered_set<string> s1;
	for (int start = 0; start < (int)str1.size(); ++start) {
		for (int end = start; end < (int)str1.size(); ++end) {
			s1.insert(str1.substr(start, end - start + 1));
		}
	}

	unordered_set<string> s2;
	for (int start = 0; start < (int)str2.size(); ++start) {
		for (int end = start; end < (int)str2.size(); ++end) {
			s2.insert(str2.substr(start, end - start + 1));
		}
	}

	int cnt = 0;
	for (string str : s1)
		cnt += s2.count(str);

	return cnt;
}

int count_anagram_substrings(const string& str) {	// O(L^3 logL)
	// Add all substrings but sort them first
	// This way same anagrams ALL have same sorted string
	unordered_set<string> s1;
	for (int start = 0; start < (int)str.size(); ++start) {
		for (int end = start; end < (int)str.size(); ++end) {
			string sub = str.substr(start, end - start + 1);	// O(L)
			sort(sub.begin(), sub.end());	// O(LlogL)
			s1.insert(sub);
		}
	}
	return s1.size();
}

// This class will help unordered_set get hash for the object, you need to know operator overloading
struct VectorHash {
	size_t operator()(const std::vector<int>& v) const {
		// No need to worry how implemented.
		// src: https://stackoverflow.com/questions/29855908/c-unordered-set-of-vectors
		hash<int> hasher;

		size_t seed = 0;
		for (int i : v)
			seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);

		return seed;
	}
};
int count_anagram_substrings_V2B(const string& str) {	// O(L^3)
	unordered_set<vector<int>, VectorHash> s1;
	for (int start = 0; start < (int)str.size(); ++start) {
		for (int end = start; end < (int)str.size(); ++end) 
		{
			vector<int> freq(26);	// O(const)
			for (int i = start; i <= end; ++i)
				++freq[str[i] - 'a'];
			s1.insert(freq);
		}
	}

	return s1.size();
}

class LinkedList
{
	struct Node
	{
		int data{};
		Node* next{};
		Node(int data) : data(data) {}
	};

private:
	Node* head{};
	Node* tail{};
	int length = 0;

public:
	void print()
	{
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}
	void insert_end(int value)
	{
		Node* item = new Node(value);

		if (!head)
			head = tail = item;
		else
		{
			tail->next = item;
			tail = item;
		}
		++length;
	}
	void create_cycle()
	{
		for (int i = 0; i < 4; ++i)
			insert_end(i);
		Node* now = tail;
		for (int i = 0; i < 3; ++i)
			insert_end(14 + i);
		tail->next = now; // cycle
	}
	void remove_cycle()
	{
		// set of addresses
		unordered_set<Node*> visited;

		for (Node* prev = nullptr, *cur = head; cur; prev = cur, cur = cur->next)
		{
			if (visited.count(cur))
			{
				prev->next = nullptr;
				tail = prev;
				break;
			}
			visited.insert(cur);
		}
	}
};

int hash_string(string str, int n = 65407) {
	long long nn = n;
	long long sum = 0;
	for (int i = 0; i < (int)str.size(); ++i)
		sum = (sum * 26 + str[i] - 'a') % nn;
	return sum % nn;
}
struct PhoneEntry {
	const static int INTERNAL_LIMIT = 65407;
	string name;			// key
	string phone_number;	// data

	int hash() {
		return hash_string(name, INTERNAL_LIMIT);
	}

	PhoneEntry(string name, string phone_number) :
		name(name), phone_number(phone_number) {
	}

	void print() {
		cout << "(" << name << ", " << phone_number << ")  ";
	}
};
class PhoneHashTable {
private:
	int table_size;
	vector<PhoneEntry*> table;
	// to mark a cell as deleted
	PhoneEntry* deleted{};
public:
	PhoneHashTable(int table_size) :
		table_size(table_size) {
		table.resize(table_size);
		deleted = new PhoneEntry("", "");
	} //  needs a destructor

	void put(PhoneEntry phone) {
		/*
		 * When to stop?
		 * One might stop when he performs table_size steps
		 * my impression: we better stop when we cycle back to same index
		 *
		 * Computionally, we can see that we can fail to add in both cases
		 * ALTHOUGHT there are still free elements!
		 * This never happens in linear probing
		 *
		 * If we failed to add: then do rehashing and try again
		 * 	which will typically works well (or do rehashing again)		 *
		 */

		int idx = phone.hash() % table_size;
		int step = 0, original_idx = idx;

		do {
			if (table[idx] == deleted || !table[idx]) {
				table[idx] = new PhoneEntry(phone.name, phone.phone_number);
				return;
			}
			else if (table[idx]->name == phone.name) {
				table[idx]->phone_number == phone.phone_number;
				return;	// update
			}
			++step;
			idx = (original_idx + step * step) % table_size;
		} while (idx != original_idx);	// catch that we repeated

		// If we failed: rehash to increase size, then add this element
		rehashing();
		put(phone);
	}

	bool remove(PhoneEntry phone) {
		int idx = phone.hash() % table_size;
		int step = 0, original_idx = idx;

		do {
			if (!table[idx])
				break;
			if (table[idx] != deleted && table[idx]->name == phone.name) {
				delete table[idx];
				table[idx] = deleted;
				return true;
			}
			++step;
			idx = (original_idx + step * step) % table_size;
		} while (idx != original_idx);	// catch that we repeated
		return false;
	}

	bool get(PhoneEntry& phone) {
		int idx = phone.hash() % table_size;
		int step = 0, original_idx = idx;

		do {
			if (!table[idx])
				break;
			if (table[idx] != deleted && table[idx]->name == phone.name) {
				phone.phone_number = table[idx]->phone_number;
				return true;
			}
			++step;
			idx = (original_idx + step * step) % table_size;
		} while (idx != original_idx);	// catch that we repeated
		return false;
	}

	void rehashing() {
		cout << "Rehashing\n";
		PhoneHashTable new_table(2 * table_size);

		for (int hash = 0; hash < table_size; ++hash) {
			if (table[hash] == deleted || !table[hash])
				continue;

			new_table.put(*table[hash]);
		}
		// Copy & delete
		table_size *= 2;
		table = new_table.table;
	}

	void print_all() {
		for (int hash = 0; hash < table_size; ++hash) {
			cout << hash << " ";
			if (table[hash] == deleted)
				cout << " X ";
			else if (!table[hash])
				cout << " E ";
			else
				table[hash]->print();
			cout << "\n";
		}
		cout << "******************\n";
	}
};

int main()
{
    
}