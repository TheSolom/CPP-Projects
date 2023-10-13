#include <iostream>
#include <map>
using namespace std;

using GRAPH = map <string, multimap <string, int>>;

void add_directed_edge(GRAPH& graph, string from, string to, int cost)
{
	graph[from].insert(make_pair(to, cost));
}

void print_adjaceny_matrix(GRAPH& graph)
{
	cout << "\n";
	for (auto i = graph.begin(); i != graph.end(); i++)
	{
		cout << "Flights from " << i->first << ": \n";
		for (auto j = i->second.begin(); j != i->second.end(); j++)
		{
			cout << "\tTo " << j->first << " with cost " << j->second << "\n";
		}
	}
}

int main()
{
	int nodes, edges;
	cin >> nodes >> edges;
	
	GRAPH graph;

	for (int i = 0; i < edges; i++)
	{
		string from, to;
		int cost;
		cin >> from >> to >> cost;

		add_directed_edge(graph, from, to, cost);
	}

	print_adjaceny_matrix(graph);
}