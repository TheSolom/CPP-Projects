#include <iostream>
#include <vector>
using namespace std;

int hash_num(int value, long long n = 65407) { // +ve or -ve
	return (value % n + n) % n;
}

int hash_string(string str, long long n = 65407) {
	long long sum = 0;
	for (int i = 0; i < (int)str.size(); i++)
		sum = (sum * 26 + str[i] - 'a') % n; // 26 for lowers >> int base 26

	return sum;
}

int hash_string_lower_upper_digits(string str, long long n = 65407) {
	int base = 26 + 26 + 10;	// 26 for lowers, 26 for uppers and 10 digits >> int base 62
	long long sum = 0;

	for (int i = 0; i < (int)str.size(); i++)
	{
		// lowers from [0-25], upper [26-51] and digits [52-61]
		int value = 0;
		if (islower(str[i]))
			value = str[i] - 'a';
		else if (isupper(str[i]))
			value = 26 + str[i] - 'A';
		else if (isdigit(str[i]))
			value = 26 + 26 + str[i] - '0'; // 26 + 26 = 52

		sum = (sum * base + value) % n;
	}

	return sum;
}

int hash_string_folding(string str, long long n = 65407) {
	long long sum = 0;
	for (int i = 0; i < (int)str.size(); i += 4) {
		string block = str.substr(i, 4);
		sum += hash_string_lower_upper_digits(block, n);
		sum %= n;
	}

	return sum;
}

struct hash_three_items {
	const static long long INTERNAL_LIMIT = 2147483647;
	string firstname, secondname;
	int number;

	hash_three_items(string firstname, string secondname, int number) :
		firstname(firstname), secondname(secondname), number(number) {}

	// Convert all 3 elements as a hash value
	int hash() {
		// Adding both can result in overflow. Use long long
		long long res = hash_string_lower_upper_digits(firstname + secondname, INTERNAL_LIMIT);
		res += hash_num(number, INTERNAL_LIMIT); // You can also res % INTERNAL_LIMIT before hash_num()

		return res % INTERNAL_LIMIT;
	}

	void print() {
		cout << "(" << firstname << ", " << secondname << ", " << number << ")  ";
	}
};

struct PhoneEntry {
	const static long long INTERNAL_LIMIT = 65407;
	string name;			// key
	string phone_number;	// data

	PhoneEntry(string name, string phone_number) : name(name), phone_number(phone_number) {}

	int hash() {
		return hash_string(name, INTERNAL_LIMIT);
	}

	void print() {
		cout << "(" << name << ", " << phone_number << ")  ";
	}
};

class PhoneHashTable {
private:
	int table_size;
	double limit_load_factor;
	int total_elements{};
	vector<vector<PhoneEntry>> table;
	// we can use others: e.g. vector<list<PhoneEntry>>
public:
	PhoneHashTable(int table_size = 10, double limit_load_factor = 0.75) :
		table_size(table_size), limit_load_factor(limit_load_factor)
	{
		table.resize(table_size);
	}

	bool get(PhoneEntry& phone) {
		int idx = phone.hash() % table_size;

		for (int i = 0; i < (int)table[idx].size(); ++i) {
			if (table[idx][i].name == phone.name) {
				phone = table[idx][i];
				return true;
			}
		}
		return false;
	}

	void put(PhoneEntry phone) {
		int idx = phone.hash() % table_size;

		for (int i = 0; i < (int)table[idx].size(); ++i)
			if (table[idx][i].name == phone.name) {
				table[idx][i] = phone; // exist => update
				return;
			}

		total_elements++;
		rehashing();
		table[idx].push_back(phone);
	}

	bool remove(PhoneEntry phone) {
		int idx = phone.hash() % table_size;

		for (int i = 0; i < (int)table[idx].size(); ++i) {
			if (table[idx][i].name == phone.name) {
				// Swap with last and remove last in O(1)
				swap(table[idx][i], table[idx].back());
				table[idx].pop_back();
				--total_elements;
				rehashing();

				return true;
			}
		}
		return false;
	}

	void print_all() {
		for (int i = 0; i < table_size; ++i) {
			if (table[i].size() == 0)
				continue;

			cout << "Hash " << i << ": ";
			for (int j = 0; j < (int)table[i].size(); ++j)
				table[i][j].print();

			cout << "\n";
		}
	}

	void rehashing() {
		double current_loadfactor = (double)total_elements / table_size;

		if (current_loadfactor < limit_load_factor)
			return;

		PhoneHashTable temp_table(2 * table_size, limit_load_factor);

		for (int i = 0; i < table_size; i++)
			for (int j = 0; j < (int)table[i].size(); j++)
				temp_table.put(table[i][j]);

		// Assign new values to current class
		table_size *= 2;
		table = temp_table.table;
	}
};
void test_PhoneHashTable()
{
	PhoneHashTable table(3);
	table.put(PhoneEntry("mostafa", "604-401-120"));
	table.put(PhoneEntry("mostafa", "604-401-777"));	// update
	table.put(PhoneEntry("ali", "604-401-343"));
	table.put(PhoneEntry("ziad", "604-401-17"));
	table.put(PhoneEntry("hany", "604-401-758"));
	table.put(PhoneEntry("belal", "604-401-550"));
	table.put(PhoneEntry("john", "604-401-223"));

	PhoneEntry test("mostafa", "");
	if (table.get(test))
		cout << test.phone_number << "\n";	// 604-401-777

	table.print_all();
	// Hash 0: (ali, 604-401-343)  (hany, 604-401-758)  (john, 604-401-223)
	// Hash 1: (mostafa, 604-401-777)  (ziad, 604-401-17)
	// Hash 2: (belal, 604-401-550)

	cout << table.remove(PhoneEntry("smith", "")) << "\n"; // 0
	cout << table.remove(PhoneEntry("hany", "")) << "\n";  // 1
	cout << table.remove(PhoneEntry("belal", "")) << "\n"; // 1

	table.print_all();
	// Hash 0: (ali, 604-401-343)  (john, 604-401-223)
	// Hash 1: (mostafa, 604-401-777)  (ziad, 604-401-17)
}

class PhoneHashTable2 {
private:
	struct LinkedHashEntry {
		PhoneEntry item;
		LinkedHashEntry* next{};

		LinkedHashEntry(PhoneEntry item) : item(item) {}
	};

	int table_size;
	vector<LinkedHashEntry*> table;
public:
	PhoneHashTable2(int table_size) : table_size(table_size) {
		// vector of linked-lists: initially nulls
		table.resize(table_size);
		// We should destruct too
	}

	void put(PhoneEntry phone) {
		int idx = phone.hash() % table_size;

		if (!table[idx])
			table[idx] = new LinkedHashEntry(phone);
		else
		{
			LinkedHashEntry* head = table[idx];
			while (head) 
			{
				if (head->item.name == phone.name) {
					head->item = phone; // exist => update
					return;
				}

				if (!head->next)
					break;
				else
					head = head->next;
			}

			// head now is tail
			head->next = new LinkedHashEntry(phone);
		}
	}

	void print_all() {
		for (int i = 0; i < table_size; ++i) {
			if (!table[i])
				continue;

			cout << "Hash " << i << ": ";
			for (LinkedHashEntry* head = table[i]; head; head = head->next)
				head->item.print();

			cout << "\n";
		}
	}
};

int main() {
	cout << hash_string_folding("aabcdefgAxT334gfg");
}