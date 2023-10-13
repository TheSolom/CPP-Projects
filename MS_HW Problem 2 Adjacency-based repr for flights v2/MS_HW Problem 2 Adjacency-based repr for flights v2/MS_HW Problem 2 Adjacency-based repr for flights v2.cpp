#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
 * Simple utility to give ids to strings: 0, 1, 2, 3, ...N-1
 * If the string has an ID, return it
 * Otherwise, give it new ID
 *
 * Using this utility
 * 	convert from string to id
 * 	convert from id to its string
 */

class IDs
{
private:
	map <string, int> String_to_ID;
	map <int, string> ID_to_String;

public:
	int Make_ID(string& str)
	{
		if (String_to_ID.count(str))
			return String_to_ID[str];

		int id = String_to_ID.size();
		String_to_ID[str] = id;
		ID_to_String[id] = str;

		return String_to_ID[str]; // or return id
	}

	string Get_String(int& id)
	{
		return ID_to_String[id]; // return str
	}
};

struct edge {
	int to;
	int cost;
};

typedef vector<vector<edge>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to, int cost) 
{
	graph[from].push_back({to, cost});
}
void add_undirected_edge(GRAPH &graph, int from, int to, int cost)
{
	graph[from].push_back({to, cost});
	graph[to].push_back({from, cost});
}

void print_adjaceny_matrix(GRAPH &graph, IDs object)
{
	cout << "\n";
	for (int i = 0; i < graph.size(); i++)
	{
		cout << "Node " << object.Get_String(i) << " has neighbors :\n";

		for (int j = 0; j < graph[i].size(); j++)
		{
			cout << "\tto " << object.Get_String(graph[i][j].to) << " with cost " << graph[i][j].cost;
			cout << "\n";
		}
	}
}

int main()
{
	int nodes, edges;
	cin >> nodes >> edges;

	GRAPH graph(nodes);	// observe: empty lists
	IDs object; // Object of class

	for (int i = 0; i < edges; i++) 
	{
		string from, to; 
		int cost;
		cin >> from >> to >> cost;

		// Strings of (from, to) into int
		int ID_from = object.Make_ID(from);
		int ID_to = object.Make_ID(to);

		add_directed_edge(graph, ID_from, ID_to, cost);
	}

	print_adjaceny_matrix(graph, object);
}

