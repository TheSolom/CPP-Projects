#include <iostream>
using namespace std;

enum Status
{
	Clean, Dirty   //enum creat variable have two status (clean = 0, dirty = 1)
};

enum Actions
{
	Nothing, MOVE_LEFT, MOVE_RIGHT, SUCK
};

enum Location
{
	A, B
};


class Environment
{
private:
	int size[2]; // because we have A and B 


public:

	Environment() //constructor

	{
		SetEnvr();
	}

	void SetEnvr() //creat rand environment with rand setting
	{
		cout << "Envroment_setting " << endl;
		int ran = rand() % 10;  // creat random number between 0,9
		if (ran < 5)
			size[A] = Clean;
		else
			size[A] = Dirty;

		ran = rand() % 10;
		if (ran < 5)
			size[B] = Clean;
		else
			size[B] = Dirty;
	}

	int GetStatus(int location) //return state of location
	{
		return size[location];
	}

	void SetStatus(int location, int status) //update state
	{
		size[location] = status;
	}

	void PrintStatus(int agentLoaction) //print state of location depend on getstatus
	{

		cout << "Envrmt Status" << endl;
		if (GetStatus(A) == Dirty)
			cout << "A status:" << "Dirty" << endl;
		else
			cout << "A status:" << "Clean" << endl;

		if (GetStatus(B) == Dirty)
			cout << "B status:" << "Dirty" << endl;
		else
			cout << "B status:" << "Clean" << endl;
		if (agentLoaction == A)
			cout << "agent location is: A" << endl;
		else
			cout << "agent location is: B" << endl;
		cout << "================================" << endl;
	}


};

class Agent
{
public:
	int ReflexVacuum(int location, int status) // return action
	{
		if (status == Dirty)
			return SUCK;
		else if (location == A)
			return  MOVE_RIGHT;
		else
			return MOVE_LEFT;

	}
};

int main()
{

	Environment e;
	Agent a;
	int currentLocation = A;

	for (int counter = 0; counter < 10; counter++)
	{
		e.PrintStatus(currentLocation);

		if (e.GetStatus(A) == Clean && e.GetStatus(B) == Clean)
			e.SetEnvr();

		int agentAction = a.ReflexVacuum(currentLocation, e.GetStatus(currentLocation));

		if (agentAction == SUCK)
			e.SetStatus(currentLocation, Clean);
		else if (agentAction == MOVE_RIGHT)
			currentLocation = B;
		else

			currentLocation = A;
	}
}