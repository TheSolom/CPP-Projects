#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int from;
    int to;
    int cost;
};

typedef vector <Edge> GRAPH;

void add_edge(GRAPH &graph, int from, int to, int cost)
{
    graph.push_back({ from, to, cost });
}

void Sort(GRAPH &graph)
{
    int size = (int) graph.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (graph[j].cost < graph[j + 1].cost)
            {
                swap(graph[j], graph[j + 1]);
            }
        } 
    }
}

void print_adjaceny_matrix(GRAPH& graph)
{
    int size = (int)graph.size();
    for (int i = 0; i < size; i++)
    {
        cout << graph[i].cost << endl;
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph;
    int from, to, cost;

    for (int i = 0; i < edges; i++)
    {
        cin >> from >> to >> cost;

        add_edge(graph, from, to, cost);
    }

    Sort(graph);
    print_adjaceny_matrix(graph);
}