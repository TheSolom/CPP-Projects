#include <iostream>
#include <algorithm>
using namespace std;

int book_index = 0, user_index = 0;

struct Book
{
	int id;
	string name;
	int total_quantity;
	int total_borrowed;

	Book() {
		id = -1;
		name = "";
		total_quantity = total_borrowed = 0;
	}
};
	
struct User
{
	int id = -1;
	string name = "";
	int borrowed_ids[11];
};

Book books[10];
User users[50];

void add_book()
{
	int book_id;
	string book_name;
	int book_quantity;

	cout << "\nEnter book id, name and total quantity: ";
	cin >> book_id >> book_name >> book_quantity;
	cout << "\n";

	books[book_index].id = book_id;
	books[book_index].name = book_name;
	books[book_index].total_quantity = book_quantity;
	++book_index;
}

void search_books_by_prefix()
{
	string book_name;
	cout << "\nEnter book name prefix: ";
	cin >> book_name;
	cout << "\n";

	bool founded = false;
	for (int i = 0; i < book_index; i++)
	{
		bool flag = false;
		for (int j = 0; j < book_name.size(); j++)
		{
			if (book_name[j] != books[i].name[j])
				break;
			flag = true;
		}

		if (flag)
		{
			cout << books[i].name << "\n";
			founded = true;
		}
	}

	if (!founded)
		cout << "Sorry not found\n";
}

void print_who_borrowed_book_by_name()
{
	string book_name;
	cout << "\nEnter book name: ";
	cin >> book_name;

	for (int i = 0; i < book_index; i++)
	{	
		if (books[i].name == book_name)
		{
			int index = 0;
			for (int j = 0; j < user_index; j++)
			{
				if (users[j].borrowed_ids[index++] == books[i].id)
					cout << users[j].name << "\n";
			}
		}
	}
}

bool cmp_id(Book& a, Book& b) {
	return a.id < b.id;
}

void print_library_by_id()
{
	sort(books, books + book_index, cmp_id);
	cout << "\n";
	for (int i = 0; i < book_index; i++)
	{
		cout << "\nId: " << books[i].id << ", Name: " << books[i].name << ", Total borrowed: "
			<< books[i].total_borrowed << ", Total quantity: " << books[i].total_quantity << "\n";
	}
}

bool cmp_name(Book& a, Book& b) {
	return a.name < b.name;
}

void print_library_by_name()
{
	sort(books, books + book_index, cmp_name);
	cout << "\n";
	for (int i = 0; i < book_index; i++)
	{
		cout << "\nId: " << books[i].id << ", Name: " << books[i].name << ", Total borrowed: "
			<< books[i].total_borrowed << ", Total quantity: " << books[i].total_quantity << "\n";
	}
}

void add_user()
{
	int user_id;
	string user_name;

	cout << "\nEnter user id and user name: ";
	cin >> user_id >> user_name;
	cout << "\n";

	users[user_index].id = user_id;
	users[user_index].name = user_name;
	++user_index;
}

void user_borrow_book()
{
	string user_name, book_name;
	int borrowed_ids_index = 0;

	cout << "\nEnter user name and book name: ";
	cin >> user_name >> book_name;

	for (int i = 0; i < book_index; i++)
	{
		if (books[i].name == book_name)
		{
			for (int j = 0; j < user_index; j++)
			{
				if (users[j].name == user_name && books[i].total_quantity > 0)
				{
					books[i].total_borrowed++;
					books[i].total_quantity--;
					users[j].borrowed_ids[i] = books[i].id;
					return;
				}
			}

			cout << "\nBook not available\n";	
		}
		else
			cout << "\nBook not found\n";
	}
}

void user_return_book()
{
	string user_name, book_name;

	cout << "\nEnter user name and book name: ";
	cin >> user_name >> book_name;

	for (int i = 0; i < book_index; i++)
	{
		if (books[i].name == book_name)
		{
			for (int j = 0; j < user_index; j++)
			{
				if (users[j].name == user_name && books[i].total_quantity > 0)
				{
					books[i].total_borrowed--;
					books[i].total_quantity++;
					users[j].borrowed_ids[i] = 0;
					return;
				}
			}
		}
		else
			cout << "\nBook not found\n";
	}
}

void print_users()
{
	for (int i = 0; i < user_index; i++)
	{
		cout << "\nId: " << users[i].id << " Name: " << users[i].name 
			<< " borrowed books ids: ";
		for (const int& it : users->borrowed_ids)
		{
			if (it > 0)
				cout << it << " ";
		}
			cout << "\n";
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
		int choice = -1;
		cin >> choice;

		Action(choice);
	}
}