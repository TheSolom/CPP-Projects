#include <iostream>
#include <vector>
using namespace std;

using GRAPH = vector <vector <vector<int>>>;

void add_directed_edge(GRAPH& graph, int from, int to, int cost)
{
	graph[from][to].push_back(cost);
}

void add_undirected_edge(GRAPH& graph, int from, int to, int cost)
{
	graph[from][to].push_back(cost);
	graph[to][from].push_back(cost);
}

void print_adjaceny_matrix(GRAPH& graph)
{
	int size = (int)graph.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < graph[i][j].size(); k++) // or ForEach
			{
				cout << "From " << i << " to " << j << " the cost is " << graph[i][j][k];
				cout << "\n";
			}
		}
	}
}

int main()
{
	int nodes, edges;
	cin >> nodes >> edges;

	GRAPH graph(nodes, vector <vector<int>> (nodes));

	for (int i = 0; i < edges; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;

		add_directed_edge(graph, from, to, cost);
	}
	print_adjaceny_matrix(graph);
}