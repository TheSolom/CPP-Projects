#include <iostream>
#include <unordered_map>
using namespace std;

class User {
private:
	string username{}, email{}, password{}, name{};
	bool isAdmin{};
	static unordered_map<string, User*> users;

	const bool IsUsernameUnique(const string& username) {
		if (users.count(username) == 0)
			return true;
		return false;
	}

public:
	User() = default;

	User(const string& username, const string& email, const string& password, const string& name, bool isAdmin = 0)
		: username(username), email(email), password(password), name(name), isAdmin(isAdmin)
	{
		if (IsUsernameUnique(username)) {
			users[username] = this;
		}
		else {
			delete this;
			cout << "Username is already used, try another one\n";
		}
	}

	const int getisAdmin() const {
		if (isAdmin == true)
			return 1;
		else if (isAdmin == false)
			return 0;
		else
			return -1;
	}

	static User* authentication(const string& username, const string& password) {
		if (users.count(username)) {
			if (users[username]->password == password) {
				return users[username];
			}
		}
		return nullptr;
	}
};

unordered_map<string, User*> User::users;

class UserController {
private:

public:
	const User* login() {
		cout << "Enter email (no spaces): \n";
		string username; cin >> username;
		cout << "Enter password (no spaces): \n";
		string password; cin >> password;

		User* user = User::authentication(username, password);
		if (!user) {
			cout << "Incorrect username or password, try again\n";
			return login();
		}
		else
			return user;
	}

	const User* signup() {
		cout << "Enter username (no spaces): \n";
		string username; cin >> username;
		cout << "Enter email (no spaces): \n";
		string email; cin >> email;
		cout << "Enter password (no spaces): \n";
		string password; cin >> password;
		cout << "Enter your name (no spaces): \n";
		string name; cin >> name;

		User* user = new User(username, email, password, name);
		if (user->getisAdmin() == -1) {
			cout << "Incorrect username or password, try again\n";
			return signup();
		}
		else
			return user;
	}
};

void UserView() {
	UserController usercontroller;
	User user;

	cout << "Menu:\n\t";
	cout << "1: Login\n\t2: Sign up";
	cout << "\nEnter 1 or 2: ";

	int choose;
	cin >> choose;

	if (choose == 1)
		user = *usercontroller.login();
	else if (choose == 2)
		user = *usercontroller.signup();
	else {
		cout << "Invalid input\n";
		return UserView();
	}
}

int main()
{
	UserView();

	return 0;
}