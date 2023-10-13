#include <iostream>
#include <vector>
using namespace std;

int spec; 
bool sts;
string name;

struct patient_details
{
	string name_of_patient;
	bool sts_of_patient;
};

vector <vector<patient_details>> spec_array(21);

void Add_Patient()
{
	cout << "Enter spec, name and sts: ";
	cin >> spec >> name >> sts;

	if (spec_array[spec].size() < 5 && sts == 1)
	{
		spec_array[spec].insert(spec_array[spec].begin(), {name, sts});
	}	
	else if(spec_array[spec].size() < 5 && sts == 0)
	{
		spec_array[spec].push_back({ name, sts });
	}
	else
		cout << "Sorry, We cannot add more patients\n\n";
}

void Print_Patients()
{
	for (int i = 0; i < 21; i++)
	{
		if (spec_array[i].size() == 0)
			continue;

		cout << "There are " << spec_array[i].size() << " patients in spec " << i << "\n";
		for (int j = 0; j < spec_array[i].size(); j++)
		{
			cout << spec_array[i][j].name_of_patient << " " << spec_array[i][j].sts_of_patient << "\n";
		}
	}
}

void Get_Patient()
{
	cout << "Enter spec: ";
	cin >> spec;

	cout << spec_array[spec][0].name_of_patient << ", please go with the doctor\n\n";

	spec_array[spec].erase(spec_array[spec].begin());
}

void Action(int& choice)
{
	if (choice == 4)
		return;
	else if (choice == 1)
		Add_Patient();
	else if (choice == 2)
		Print_Patients();
	else if (choice == 3)
		Get_Patient();
}

int main()
{
	while (true)
	{
		cout << "Enter your choice:\n"
		<< "1) Add new patient\n"
		<< "2) Print all patients\n"
		<< "3) Get next patient\n"
		<< "4) Exit\n";

		int choice;
		cin >> choice;

		Action(choice);

	}

}