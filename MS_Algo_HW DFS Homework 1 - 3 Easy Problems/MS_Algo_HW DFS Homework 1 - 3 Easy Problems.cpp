#include <iostream>
#include <vector>
#include <unordered_map>
#include<unordered_set>
using namespace std;

class Solution2 {
private:
	class Employee {
	public:
		int id;
		int importance;
		vector<int> subordinates;
	};

	unordered_map<int, Employee*> id_to_emp;

public:
	int getImportance(vector<Employee*> employees, int id) {
		for (const auto& emp : employees)
			id_to_emp[emp->id] = emp;

		return dfs(id);
	}

	// Why no visited array? No need for visited array in DAG, as no cycles :)
	int dfs(int id) {
		Employee* emp = id_to_emp[id];
		int result = emp->importance;

		for (const auto& emp : emp->subordinates)
			result += dfs(emp);

		return result;
	}
};

class Solution3 {
private:
	vector<vector<int>> graph;
	vector<bool> visited;
public:
	int countComponents(int nodes, vector<vector<int>>& edges) {
		graph.resize(nodes), visited.resize(nodes);

		for (int i = 0; i < (int)edges.size(); i++) {
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][0]].push_back(edges[i][0]);
		}

		return counting(nodes);
	}

	int counting(int nodes_size) 
	{
		int counter{};
		for (int i = 0; i < nodes_size; i++)
		{
			if (!visited[i]) {
				counter++;
				dfs(i);
			}
		}
	}

	int dfs(int node)
	{
		visited[node] = true;

		for (const auto& neighbour : graph[node]) {
			if (!visited[neighbour])
				dfs(neighbour);
		}
	}
};

int main()
{
	return 0;
}