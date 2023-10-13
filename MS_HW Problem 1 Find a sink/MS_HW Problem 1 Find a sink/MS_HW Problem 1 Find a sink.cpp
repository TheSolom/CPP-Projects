#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using GRAPH = vector <vector<int>>;

void add_directed_edge(GRAPH& graph, int from, int to) {
	graph[from][to] += 1;
}

int find_universal_sink_slow(GRAPH& graph)
{
	for (int col = 0; col < graph.size(); col++)
	{
		int cntr = 0;
		for (int row = 0; row < graph.size(); row++)
		{
			if (graph[row][col] > 0)
				cntr++;
		}

		if (cntr >= graph.size() - 1)
			return col;
	}
	return -1;
}

int find_universal_sink_fast(GRAPH& graph, vector<int>& freq_from, vector<int>& freq_to)
{
	int max_count = *max_element(freq_to.begin(), freq_to.end());

	auto it = find(freq_to.begin(), freq_to.end(), max_count);
	int index = it - freq_to.begin();

	if (max_count >= graph.size() - 1 && count(freq_from.begin(), freq_from.end(), index) == 0)
		return index;

	return -1;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n--)
	{
		int nodes, edges;
		cin >> nodes >> edges;
		if (edges == 0) {
			cout << "-1\n";
			return -1;
		}

		GRAPH graph(nodes, vector<int>(nodes));

		vector <int> freq_from;
		vector <int> freq_to(nodes);

		for (int e = 0; e < edges; ++e) {
			int from, to;
			cin >> from >> to;

			freq_from.push_back(from);
			freq_to[to]++;
			add_directed_edge(graph, from, to);
		}

		cout << find_universal_sink_slow(graph);
		cout << "\n";
		cout << find_universal_sink_fast(graph, freq_from, freq_to);
	}
}