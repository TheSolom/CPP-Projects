#include <iostream>
#include <vector>
using namespace std;

using GRAPH = vector <vector <int>>;

void add_directed_edge(GRAPH& graph, int from, int to) {
	graph[from].push_back(to);
}

bool flag;
void print_chain(GRAPH& graph, int from)  
{
	if (!flag) 
	{
		cout << from << " ";
		flag = true;
	}

	if (graph[from].size() > 0) 
	{
		cout << graph[from][0] << " ";
		print_chain(graph, graph[from][0]);
	}
}

void print_paths_len_2(GRAPH& graph) 
{
	for (int i = 0; i < graph.size(); i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			int middle = graph[i][j];
			if (graph[middle].size() > 0)
			{
				for (int k = 0; k < graph[middle].size(); k++)
				{
					cout << i << " " << middle << " " << graph[middle][k];
					cout << "\n";
				}
			}
		}
	}
}

int main()
{
	int nodes, edges;
	cin >> nodes >> edges;

	GRAPH graph(nodes);	// observe: empty lists

	for (int e = 0; e < edges; ++e) {
		int from, to;
		cin >> from >> to;
		add_directed_edge(graph, from, to);
	}

	/*int Q;
	cin >> Q;
	while (Q--) 
	{
		int n;
		cin >> n;

		flag = false;
		print_chain(graph, n);
		cout << "\n";
	}*/

	print_paths_len_2(graph);
}
