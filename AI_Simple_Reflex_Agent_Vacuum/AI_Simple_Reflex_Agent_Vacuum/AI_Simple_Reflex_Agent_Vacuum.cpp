#include<iostream>
#include<vector>
using namespace std;

enum Status 
{ 
    Clean, Dirty 
};
enum Actions 
{ 
    Nothing, MOVE_LEFT, MOVE_RIGHT, SUCK 
};

class Environment
{
private:

    vector <int> locations;
    int numoflocations;

public:

    Environment(int n)
    {
        locations.resize(n);
        numoflocations = n;
        SetEnvr();
    }
    void SetEnvr() {
        cout << "\t\t\t\t------ Environment Setting-----" << endl << endl;
        int ran;
        for (int i = 0; i < numoflocations; i++)
        {
            ran = rand() % 10;
            if (ran < 5)
            {
                locations[i] = Clean;
            }
            else
                locations[i] = Dirty;
        }
    }

    int GetStatusofcurrentlocation(int location)
    {
        return locations[location];
    }
    void SetStatusofcurrentlocation(int location, int status)
    {
        locations[location] = status;
    }

    void printstatus(int agentlocation) {
        cout << "..... Environment Status.... " << endl;
        for (int i = 0; i < numoflocations; i++)
        {
            if (GetStatusofcurrentlocation(i) == Dirty)
            {
                cout << "Status of location " << i + 1 << " is Dirty" << endl;
            }
            else
            {
                cout << "Status of location " << i + 1 << " is Clean" << endl;
            }
        }
        cout << "Vacuum in location " << agentlocation + 1 << endl;
    }
};

class Agent
{
private:

    int numoflocations;

public:

    Agent(int n) {
        numoflocations = n;
    }
    int Vacuumaction(int location, int status)
    {
        if (status == Dirty)
            return SUCK;
        else if (location == 0)
            return MOVE_RIGHT;
        else if (location == (numoflocations - 1))
            return MOVE_LEFT;
        else
        {
            int ran = rand() % 2;
            if (ran == 1)
            {
                return MOVE_RIGHT;
            }
            else
                return MOVE_LEFT;
        }
    }
};


int main()
{
    int numoflocations = 0;
    cout << "Enter number of locations: ";
    cin >> numoflocations;
    Environment e(numoflocations);
    Agent a(numoflocations);
    int currentLocation = 0;
    int agentAction;

    for (int counter = 0; counter < 10; counter++)
    {
        e.printstatus(currentLocation);
        bool flag = true;
        for (int i = 0; i < numoflocations; i++)
        {
            if (e.GetStatusofcurrentlocation(i) == Clean)
            {
                flag = false;
            }
            else
                flag = true;
        }

        if (!flag)
        {
            cout << "Next action is Nothing" << endl << endl;
            e.SetEnvr();
        }
        else
        {
            agentAction = a.Vacuumaction(currentLocation, e.GetStatusofcurrentlocation(currentLocation));
            if (agentAction == SUCK) {
                cout << "Next action : Suck " << endl << endl;
                e.SetStatusofcurrentlocation(currentLocation, Clean);
            }
            else if (agentAction == MOVE_RIGHT) {
                cout << "Next action : Move_Right " << endl << endl;
                currentLocation++;
            }
            else
            {
                cout << "Next action MOVE_LEFT " << endl << endl;
                currentLocation--;
            }
        }
    }
    cout << endl << endl;
};