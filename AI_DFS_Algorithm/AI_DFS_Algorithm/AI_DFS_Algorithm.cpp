#include <iostream>
#include <vector>
using namespace std;

int num_of_edges, from, to, goal, start;
vector<int>adj[150009], answer;
bool visited[150009], done;

void DFS(int node) 
{
    if (visited[node] || done)
        return;

    if (node == goal)
    {
        visited[node] = true;
        done = true;
        answer.push_back(node);
        return;
    }

    answer.push_back(node);
    visited[node] = true;
    for (auto u : adj[node]) 
    {
        DFS(u);
    }
}

int main()
{
    cout << "enter number of edges: ";
    cin >> num_of_edges;

    for (int i = 0; i < num_of_edges; i++) 
    {
        cin >> from >> to;
        adj[from].push_back(to);
    }

    cout << "Enter the goal: ";
    cin >> goal;

    cout << "Enter the starting node: ";
    cin >> start;

    DFS(start);
    cout << "the order of the nodes to reach the goal is: ";

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
}
