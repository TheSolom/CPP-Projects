#include <iostream>
using namespace std;
enum Status { Clean, Dirty };
enum Actions { Nothing, MOVE_LEFT, MOVE_RIGHT, SUCK };
enum Location { A, B };
class Environment {
private:
    int EnvrLocations[2];
public:
    Environment() {
        SetEnvr();
    }
    void SetEnvr() {
        cout << "--- Environment Setting-----" << endl;
        int ran = rand() % 10;
        if (ran < 5) {
            EnvrLocations[A] = Clean;
        }
        else
        {
            EnvrLocations[A] = Dirty;
        }

        ran = rand() % 10;
        if (ran < 5) {
            EnvrLocations[B] = Clean;
        }
        else
            EnvrLocations[B] = Dirty;
    }

    int getstatusofcurrentlocation(int location) {
        return EnvrLocations[location];
    }
    void setstatusofcurrentlocation(int location, int status) {
        EnvrLocations[location] = status;
    }




    void printstatus(int agentlocation) {
        cout << "..... Environment Status.... " << endl;
        if (getstatusofcurrentlocation(A) == Dirty) {
            cout << "Status of location A is : " << Dirty << endl;
        }
        else {
            cout << "Status of location A is : " << Clean << endl;
        }
        if (getstatusofcurrentlocation(B) == Dirty) {
            cout << "Status of location B is : " << Dirty << endl;
        }
        else {
            cout << "Status of location B is : " << Clean << endl;
        }
        if (agentlocation == A) {
            cout << "Vacuum location is A" << endl;
        }
        else
        {
            cout << "Vacuum location is B " << endl;
        }

    };
};
class Agent
{
public:
    int vacuumaction(int location, int staus) {
        if (staus == Dirty) {
            return SUCK;
        }
        else if (location == A) {
            return MOVE_RIGHT;
        }
        else {
            return MOVE_LEFT;
        }
    };
};


int main()
{
    Environment E;
    Agent a;
    int currentlocation = A;
    int agentaction;

    for (int i = 0; i < 10; i++)
    {
        E.printstatus(currentlocation);
        if (E.getstatusofcurrentlocation(A) == Clean && E.getstatusofcurrentlocation(B) == Clean) {
            agentaction = Nothing;
            cout << "Next action" << agentaction << endl;
            E.SetEnvr();
        }
        else
        {
            agentaction = a.vacuumaction(currentlocation, E.getstatusofcurrentlocation(currentlocation));
            if (agentaction == SUCK) {
                cout << "Next action : Suck " << endl;
                E.setstatusofcurrentlocation(currentlocation, Clean);
            }
            else if (agentaction == MOVE_RIGHT) {
                cout << "Next action : Move_Right " << endl;
                currentlocation = B;
            }
            else
            {
                cout << "Next action MOVE_LEFT " << endl;
                currentlocation = A;
            }
        }
    }
}