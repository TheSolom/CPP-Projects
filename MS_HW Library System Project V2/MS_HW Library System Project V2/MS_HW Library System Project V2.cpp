#include <iostream>
#include <algorithm>
using namespace std;

int book_index {}, user_index {};

struct Book {
	int id;
	string name;
	int total_quantity;
	int total_borrowed;

	Book() {
		id = -1;
		name = "";
		total_quantity = total_borrowed = 0;
	}

	void read() {
		cout << "\nEnter book id, name and total quantity: ";
		cin >> id >> name >> total_quantity;
		cout << "\n";
	}

	bool has_prefix(string book_prefix) {
		if (book_prefix > name)
			return false;

		for (int i = 0; i < book_prefix.size(); i++)
		{
			if (book_prefix[i] != name[i])
				return false;
		}
		return true;
	}

	void print() {
		cout << "\nId: " << id << ", Name: " << name << ", Total borrowed: "
			<< total_borrowed << ", Total quantity: " << total_quantity << "\n";
	}

	void borrow() {
		total_borrowed++;
		total_quantity--;
	}

	void return_copy() {
		total_borrowed--;
		total_quantity++;
	}
};

Book books[10];

struct User {
	int id;
	string name;
	int borrowed_len;
	int borrowed_ids[10];

	User() {
		id = -1;
		name = "";
		borrowed_len = 0;
		borrowed_ids[10] = {};
	}

	void read() {
		cout << "Enter id and name: ";
		cin >> id >> name;
	}

	bool is_borrowed(int book_id) {
		int index = 0;
		for (int i = 0; i < user_index; i++)
		{
			if (borrowed_ids[index++] == book_id)
				return true;
		}
		return false;
	}

	void borrow(int book_id) {
		borrowed_ids[borrowed_len++] = book_id;
	}

	void return_copy(int book_id) {
		bool removed = false;
		for (int i = 0; i < borrowed_len; i++)
		{
			if (borrowed_ids[i] == book_id)
			{
				for (int j = 0; j < borrowed_len; j++)
					borrowed_ids[i] = borrowed_ids[i + 1];
				removed = true;
				return;
			}
		}

		if (!removed)
			cout << name << " didn't borrow book with id" << book_id << "\n";
	}

	void print() {
		cout << "User: " << name << ", id: " << id << ", borrowed books ids: ";
		for (int i = 0; i < borrowed_len; ++i)
			cout << borrowed_ids[i] << " ";
		cout << "\n";
	}
};

User users[50];

void add_book()
{
	books[book_index++].read();
}

void search_books_by_prefix()
{
	cout << "\nEnter book name prefix: ";
	string book_prefix;
	cin >> book_prefix;
	cout << "\n";

	for (int i = 0; i < book_index; i++)
	{
		if (books[i].has_prefix(book_prefix))
		{
			cout << books[i].name << "\n";
		}
	}
}

int find_book_idx_by_name(string book_name)
{
	for (int i = 0; i < book_index; i++)
	{
		if (books[i].name == book_name)
			return i;
	}
	return -1;
}

void print_who_borrowed_book_by_name()
{
	cout << "\nEnter book name: ";
	string book_name;
	cin >> book_name;

	int book_idx = find_book_idx_by_name(book_name);

	if (book_idx == -1) {
		cout << "\nInvalid book name.\n";
		return;
	}
	if (books[book_idx].total_borrowed == 0) {
		cout << "\nNo borrowed copies\n";
		return;
	}

	int book_id = books[book_idx].id;

	for (int i = 0; i < user_index; i++)
	{
		if (users[i].is_borrowed(book_id))
			cout << users[i].name << "\n";
	}
}

bool cmp_id(Book& a, Book& b) {
	return a.id < b.id;
}

void print_library_by_id()
{
	if (book_index == 0)
		cout << "\nSorry there is no books\n";

	sort(books, books + book_index, cmp_id);
	cout << "\n";

	for (int i = 0; i < book_index; i++)
		books[i].print();
}

bool cmp_name(Book& a, Book& b) {
	return a.name < b.name;
}

void print_library_by_name()
{
	if (book_index == 0)
		cout << "\nSorry there is no books\n";

	sort(books, books + book_index, cmp_name);
	cout << "\n";

	for (int i = 0; i < book_index; i++)
		books[i].print();
}

void add_user()
{
	users[user_index++].read();
}

int find_user_idx_by_name(string user_name)
{
	for (int i = 0; i < user_index; i++)
	{
		if (users[i].name == user_name)
			return i;
	}
	return -1;
}

void user_borrow_book()
{
	cout << "\nEnter user name and book name: ";

	string user_name, book_name;
	cin >> user_name >> book_name;

	int book_idx = find_book_idx_by_name(book_name);
	int user_idx = find_user_idx_by_name(user_name);

	if (book_idx == -1) {
		cout << "\nInvalid book name.\n";
		return;
	}
	if (books[book_idx].total_quantity == 0) {
		cout << "\nNo enough copies\n";
		return;
	}
	if (user_idx == -1) {
		cout << "\nInvalid user name.\n";
		return;
	}
	
	int book_id = books[book_idx].id;

	users[user_idx].borrow(book_id);
	books[book_idx].borrow();
}

void user_return_book()
{
	string user_name, book_name;
	cin >> user_name >> book_name;

	int book_idx = find_book_idx_by_name(book_name);
	int user_idx = find_user_idx_by_name(user_name);

	if (book_idx == -1) {
		cout << "\nInvalid book name.\n";
		return;
	}
	if (books[book_idx].total_borrowed == 0) {
		cout << "\nNo borrowed copies\n";
		return;
	}
	if (user_idx == -1) {
		cout << "\nInvalid user name.\n";
		return;
	}

	int book_id = books[book_idx].id;

	users[user_idx].return_copy(book_id);
	books[book_idx].return_copy();
}

void print_users()
{
	if (user_index == 0)
		cout << "\nSorry there is no users\n";

	for (int i = 0; i < user_index; i++)
	{
		cout << "\n";
		users[i].print();
	}
}

void Action(int& choice)
{
	if (choice == 1)
		add_book();
	else if (choice == 2)
		search_books_by_prefix();
	else if (choice == 3)
		print_who_borrowed_book_by_name();
	else if (choice == 4)
		print_library_by_id();
	else if (choice == 5)
		print_library_by_name();
	else if (choice == 6)
		add_user();
	else if (choice == 7)
		user_borrow_book();
	else if (choice == 8)
		user_return_book();
	else if (choice == 9)
		print_users();
	else
		return;
}

int main()
{
	while (true)
	{
		cout << "\nLibrary Menu;\n";
		cout << "1) add_book\n";
		cout << "2) search_books_by_prefix\n";
		cout << "3) print_who_borrowed_book_by_name\n";
		cout << "4) print_library_by_id\n";
		cout << "5) print_library_by_name\n";
		cout << "6) add_user\n";
		cout << "7) user_borrow_book\n";
		cout << "8) user_return_book\n";
		cout << "9) print_users\n";
		cout << "10) Exit\n";

		cout << "\nEnter your menu choice [1 - 10]: ";
		int choice;
		cin >> choice;

		Action(choice);
		return 0;
	}
}