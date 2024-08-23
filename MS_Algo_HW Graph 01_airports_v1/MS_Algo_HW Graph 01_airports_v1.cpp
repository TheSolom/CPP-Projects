#include <iostream>
#include <map>
#include <set>
using namespace std;

struct Edge {
	string to;
	int cost;

	bool operator < (const Edge& other) const {
		return to != other.to ? to < other.to : cost < other.cost;
	}
};

void print_graph(const map<string, multiset<Edge>>& graph) {
	for(const auto& mp : graph)
	{
		cout << "Flights from " << mp.first << ":\n";
		for (const auto& st : mp.second)
		{
			cout << "\tTo " << st.to << " with cost " << st.cost << "\n";
		}
	}
}

int main()
{
	int nodes, edges;
	cin >> nodes >> edges;

	map<string, multiset<Edge>> graph;

	string from, to;
	int cost;
	for (int i = 0; i < edges; i++)
	{
		cin >> from >> to >> cost;

		graph[from].insert({ to, cost });
	}

	print_graph(graph);
}