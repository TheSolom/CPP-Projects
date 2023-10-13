#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

using GRAPH = vector <unordered_set<int>>;

void add_directed_edge(GRAPH& graph, int from, int to)
{
    graph[from].insert(to);
}

void add_undirected_edge(GRAPH& graph, int from, int to)
{
    graph[from].insert(to);
    graph[to].insert(from);
}

void print_adjaceny_matrix(GRAPH& graph)
{
    int size = (int)graph.size();
    for (int i = 0; i < size; i++)
    {
        cout << "Node " << i << " has those neighbors ";
        for (const int &j : graph[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph (nodes);
    for (int i = 0; i < edges; i++)
    {
        int from, to;
        cin >> from >> to;

        add_directed_edge(graph, from, to);
    }

    print_adjaceny_matrix(graph);
}