#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

vector<string> read_file(string path) {
	vector<string> lines;

	fstream file_handler(path.c_str());

	if (file_handler.fail()) {
		cout << "\n\nERROR: Can't open the file\n\n";
		return lines;
	}
	string line;

	while (getline(file_handler, line)) {
		if (line.size() == 0)
			continue;
		lines.push_back(line);
	}

	file_handler.close();
	return lines;
}
void write_file(string path, vector<string> lines, bool append = true) {
	auto status = ios::in | ios::out | ios::app;

	if (!append)
		status = ios::in | ios::out | ios::trunc;	// overwrite

	fstream file_handler(path.c_str(), status);

	if (file_handler.fail()) {
		cout << "\n\nERROR: Can't open the file\n\n";
		return;
	}

	for (auto line : lines) {
		file_handler << line;
		file_handler << "\n";
	}

	file_handler.close();
}
vector<string> SplitString(string s, string delimiter = ",") {
	vector<string> strs;

	int pos = 0;
	string substr;
	while ((pos = (int)s.find(delimiter)) != -1) {
		substr = s.substr(0, pos);
		strs.push_back(substr);
		s.erase(0, pos + delimiter.length());
	}
	strs.push_back(s);
	return strs;
}


class User
{
private:
	string id, name, password, user_name, email, AQ;

public:
	User() {
		id = name = password = user_name = email = AQ = "";
	}

	User(const string& name, const string& password, const string& user_name, const string& email, const string AQ = "1")
		: name(name), password(password), user_name(user_name), email(email), AQ(AQ)
	{
		id = to_string(1 + (rand() % 10));

		vector<string> user_data {id + "," + name + "," + password + "," + user_name + "," + email + "," + AQ + ","};
		write_file("C:/Users/eslam/Downloads/Mostafa Saad/19 Project #3/users.txt", user_data);
	}

	pair<bool, string> authentication(string user_name, string password) {
		vector<string> users_login_info;
		users_login_info = read_file("C:/Users/eslam/source/repos/MS_HW AskMe Project/users.txt");

		for (int i = 0; i < users_login_info.size(); i++)
		{
			vector<string> userData = SplitString(users_login_info[i]);

			if (userData[2] == password && userData[3] == user_name)
				return { true, userData[0] };
		}
		return { false, "" };
	}

	string getId() {
		return id;
	}

	static bool getAQ(string id) {
		vector<string> users_info;
		users_info = read_file("C:/Users/eslam/source/repos/MS_HW AskMe Project/users.txt");

		for (int i = 0; i < users_info.size(); i++)
		{
			vector<string> userData = SplitString(users_info[i]);

			if (userData[0] == id)
				return userData[5] == "1";
		}
	}

	static void list_users() {
		vector<string> users_info;
		users_info = read_file("C:/Users/eslam/source/repos/MS_HW AskMe Project/users.txt");

		for (int i = 0; i < users_info.size(); i++)
		{
			vector<string> userData = SplitString(users_info[i]);

			cout << "ID:  " << userData[0] << "\tName:  " << userData[3] << "\n";
		}
	}
};

class users_manager
{
private:
	User current_user;

public:
	string access_system() {
		cout << "\n1: Login\n2: Signup\n\nChoose 1 or 2: ";
		int choice;
		cin >> choice;

		if (choice == 1)
			return do_login();
		else if (choice == 2)
			return do_signup();
		else
			cout << "\nInvalid choice\n";
	}

	int choice() {
		cout << "\n1: Print Questions To Me";
		cout << "\n2: Print Questions From Me";
		cout << "\n3: Answer Question";
		cout << "\n4: Delete Question";
		cout << "\n5: Ask Question";
		cout << "\n6: List System Users";
		cout << "\n7: Feed";
		cout << "\n8: Logout";
		cout << "\n0: Exit";

		cout << "\nEnter number in range 1 ~ 8: ";
		int choice;
		cin >> choice;

		return choice;
	}

	string do_signup() {
		cout << "\nEnter username:(no spaces)  ";
		string user_name;
		cin >> user_name;

		cout << "\nEnter password: ";
		string password;
		cin >> password;

		cout << "\nEnter name: ";
		string name;
		cin >> name;

		cout << "\nEnter email: ";
		string email;
		cin >> email;

		cout << "\nAllow aq?: (0 or 1)";
		string AQ;
		cin >> AQ;

		User current_user(name, password, user_name, email, AQ);

		return current_user.getId();
	}

	string do_login() {
		cout << "\nEnter username & password: ";
		string login_user_name, login_password;
		cin >> login_user_name >> login_password;

		pair<bool, string> us = current_user.authentication(login_user_name, login_password);
		if (!us.first) {
			cout << "\nInvlaid username or password\n";
			do_login();
		}

		return us.second;
	}

	void list_system_users() {
		User::list_users();
	}
};


class Question
{
private:
	string id = "", parent_id = "-1", from = "", to = "", AQ = "1", question = "", answer = "";

public:
	Question() = default;

	Question(const string& parent_id, const string& from, const string& to, const string& AQ = "1", const string& question = "", const string& answer = "")
		: parent_id(parent_id), from(from), to(to), AQ(AQ), question(question), answer(answer)
	{
		id = to_string(1 + (rand() % 100));

		vector<string> question_data {id + "," + parent_id + "," + from + "," + to + "," + AQ + "," + question + "," + answer};
		write_file("C:/Users/eslam/Downloads/Mostafa Saad/19 Project #3/questions.txt", question_data);
	}

	vector<vector<vector<string>>> print_questions_to_me(string id) {
		vector<string> questions_info;
		questions_info = read_file("C:/Users/eslam/source/repos/MS_HW AskMe Project/questions.txt");

		vector<vector<vector<string>>> questions;
		map<string, int> parents;
		for (int i = 0; i < questions_info.size(); i++)
		{
			vector<string> questionData = SplitString(questions_info[i]);

			if (questionData[3] == id)
			{
				if (questionData[1] == "-1") {
					questions.push_back({ questionData });
					parents.insert({ questionData[0], questions.size() - 1 });
				}
				else {
					int parent_idx = parents[questionData[1]];
					questions[parent_idx].push_back(questionData);
				}
			}
		}

		return questions;
	}

	vector<vector<string>> print_questions_from_me(string id) {
		vector<string> questions_info;
		questions_info = read_file("C:/Users/eslam/source/repos/MS_HW AskMe Project/questions.txt");

		vector<vector<string>> questions;
		for (int i = 0; i < questions_info.size(); i++)
		{
			vector<string> questionData = SplitString(questions_info[i]);

			if (questionData[2] == id)
				questions.push_back(questionData);
		}

		return questions;
	}

	void answer_question(string id, string qs_id, string answer) {
		vector<string> questions_info;
		questions_info = read_file("C:/Users/eslam/source/repos/MS_HW AskMe Project/questions.txt");

		for (int i = 0; i < questions_info.size(); i++)
		{
			vector<string> questionData = SplitString(questions_info[i]);

			if (questionData[0] == qs_id)
			{
				if (questionData.size() == 8) {
					cout << "Already answered, Answer will be updated\n";

					bool start = true;
					for (auto it = questions_info[i].rbegin(); it != questions_info[i].rend(); it++) {
						if (*it == ',' && !start) {
							break;
						}
						start = false;
						questions_info[i].pop_back();
					}
				}

				for (int k = 0; k < answer.length(); k++)
					questions_info[i].push_back(answer[k]);
				questions_info[i].push_back(',');

				break;
			}

		}

		write_file("C:/Users/eslam/Downloads/Mostafa Saad/19 Project #3/questions.txt", questions_info, false);
	}

	void delete_question(string id, string qs_id) {
		vector<string> questions_info;
		questions_info = read_file("C:/Users/eslam/source/repos/MS_HW AskMe Project/questions.txt");

		for (int i = 0; i < questions_info.size(); i++)
		{
			vector<string> questionData = SplitString(questions_info[i]);

			if (questionData[0] == qs_id || questionData[1] == qs_id) {
				if (questionData[2] == id)
					questions_info[i].clear();
				else
					cout << "Sorry, Can't delete others questions\n";
			}
		}

		write_file("C:/Users/eslam/Downloads/Mostafa Saad/19 Project #3/questions.txt", questions_info, false);

	}

	void ask_question(string id, string parent_id, string to_id, string ques, string AQ) {
		Question question(parent_id, id, to_id, AQ, ques);
	}

	static void feed() {
		vector<string> questions_info;
		questions_info = read_file("C:/Users/eslam/source/repos/MS_HW AskMe Project/questions.txt");

		for (int i = 0; i < questions_info.size(); i++)
		{
			vector<string> questionData = SplitString(questions_info[i]);

			cout << "Question Id (" << questionData[0]
				<< ") from user id (" << questionData[2] << ")"
				<< " To user id (" << questionData[3] << ")\n";

			cout << "\tQuestion: " << questionData[5] << "\n";
			cout << "\t\tAnswer: " << questionData[6] << "\n\n";
		}
	}
};

class questions_manager
{
private:
	Question question;

public:
	void print_questions_to_me(string id) {
		vector<vector<vector<string>>> questions;
		questions = question.print_questions_to_me(id);

		for (int i = 0; i < questions.size(); i++) {
			for (int j = 0; j < questions[i].size(); j++)
			{
				if (j > 0) cout << "\tThread: ";
				cout << "Question Id (" << questions[i][j][0] << ")";

				if (questions[i][j][4] == "0")
					cout << "from user id (" << questions[i][j][2] << ")\n";

				if (j > 0) cout << "\tThread: ";
				cout << "\tQuestion: " << questions[i][j][5] << "\n";

				if (j > 0) cout << "\tThread: ";
				cout << "\t\tAnswer: " << questions[i][j][6] << "\n\n";
			}
		}
	}

	void print_questions_from_me(string id) {
		vector<vector<string>> questions;
		questions = question.print_questions_from_me(id);

		for (int i = 0; i < questions.size(); i++)
		{
			cout << "Question Id (" << questions[i][0] << ")";
			if (questions[i][4] == "0")
				cout << " !AQ ";
			cout << " To user id (" << questions[i][2] << ")\n";
			cout << "\tQuestion: " << questions[i][5] << "\n";
			cout << "\t\tAnswer: " << questions[i][6] << "\n\n";
		}
	}

	void answer_question(string id) {
		cout << "Enter question id or -1 to cancel: ";
		string qs_id;
		cin >> qs_id;

		cin.ignore();
		if (qs_id != "-1") {
			cout << "Enter your answer: ";
			string answer;
			getline(cin, answer);

			question.answer_question(id, qs_id, answer);
		}
	}

	void delete_question(string id) {
		cout << "Enter question id or -1 to cancel: ";
		string qs_id;
		cin >> qs_id;

		cin.ignore();
		if (qs_id != "-1")
			question.delete_question(id, qs_id);
	}

	void ask_question(string id) {
		cout << "Enter user id or -1 to cancel: \n";
		string user_id;
		cin >> user_id;

		if (user_id != "-1") {
			string AQ = "0";

			if (!User::getAQ(user_id))
				cout << "Note: Anonymous questions not allowed for this user\n";
			else {
				cout << "Want to ask Anonymous question? (1 or 0)";
				cin >> AQ;
			}

			cin.ignore();
			cout << "For thread question, enter question id or -1 for new question: ";
			string parent_id;
			cin >> parent_id;
			cin.ignore();

			cout << "Ask the question: ";
			string ques;
			getline(cin, ques);

			question.ask_question(id, parent_id, user_id, ques, AQ);
		}
	}

	void feed() {
		Question::feed();
	}
};


void AskMe_System()
{
	users_manager user_manager;
	questions_manager question_manager;

	string current_id = user_manager.access_system();

	int choice = user_manager.choice();

	if (choice == 1)
		question_manager.print_questions_to_me(current_id);
	else if (choice == 2)
		question_manager.print_questions_from_me(current_id);
	else if (choice == 3)
		question_manager.answer_question(current_id);
	else if (choice == 4)
		question_manager.delete_question(current_id);
	else if (choice == 5)
		question_manager.ask_question(current_id);
	else if (choice == 6)
		user_manager.list_system_users();
	else if (choice == 7)
		question_manager.feed();
	else if (choice == 8)
		AskMe_System();
	else
		return;

	AskMe_System();
}

int main()
{
	AskMe_System();
}