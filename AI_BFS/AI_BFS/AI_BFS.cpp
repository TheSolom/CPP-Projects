#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int Initialstate, numofedge, from, to, goalstste, depth[1000009];
vector<int>adj[10000], closelist;
queue<int>openlist;
bool visited[10000];

void StateSpaceGraph()
{
    cout << "enter number of edges : " << endl;
    cin >> numofedge;

    cout << "enter the edges : " << endl;
    for (int i = 0; i < numofedge; i++)
    {
        cin >> from >> to;
        adj[from].push_back(to);
    }
}

void BFS(int start)
{
    openlist.push(start);
    depth[start] = 0;
    visited[start] = true;

    while (!openlist.empty())
    {
        int currentstate = openlist.front();
        openlist.pop();
        closelist.push_back(currentstate);

        if (currentstate == goalstste)
            return;

        for (auto state : adj[currentstate])
        {
            if (visited[state])
            {
                continue;
            }

            openlist.push(state);
            visited[state] = true;
            depth[state] = depth[currentstate] + 1;
        }

    }
    return;
}

void Display()
{
    cout << "the path is => ";
    for (int i = 0; i < closelist.size(); i++)
    {
        cout << closelist[i] << "  ";
    }
    cout << "\nThe level of the goal is  " << depth[goalstste];
}


int main()
{
    StateSpaceGraph();

    cout << "enter inintal state: ";
    cin >> Initialstate;
    cout << "enter goal state : ";
    cin >> goalstste;

    BFS(Initialstate);
    Display();
}