#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
	int dr[4]{ -1, 0, 1, 0 };
	int dc[4]{ 0, 1, 0, -1 };

	bool is_sub_island;

	bool isValid(int R, int C, int i, int j) {
		return !(i < 0 || j < 0 || i >= R || j >= C);
	}

public:
	int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) { // O(NM) time and memory
		int count{};
		for (int i = 0; i < grid1.size(); i++)
			for (int j = 0; j < grid1[0].size(); j++)
				if (grid2[i][j] == 1) {
					is_sub_island = true;
					dfs(grid1, grid2, i, j);
					count += is_sub_island;
				}

		return count;
	}

	void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
		if (!isValid(grid1.size(), grid1[0].size(), i, j) || grid2[i][j] == 0)
			return;

		if (grid2[i][j] == 1 && grid1[i][j] == 0) {
			is_sub_island = false;	// Grid2 CC still has more cells!
			return;
		}

		grid2[i][j] = 0; // use the same grid to mark visited

		for (int d = 0; d < 4; d++)
			dfs(grid1, grid2, dr[d] + i, dc[d] + j);
	}
};

class Solution2 {
	const int dr[4]{ -1, 0, 1, 0 };
	const int dc[4]{ 0, 1, 0, -1 };

	vector<vector<bool>>visited;

	bool isValid(int R, int C, int i, int j) {
		return i >= 0 && j >= 0 && i < R && j < C;
	}

public:
	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
		visited.resize(grid.size(), vector<bool>(grid[0].size()));

		dfs(grid, row, col, grid[row][col], color);

		return grid;
	}

	void dfs(vector<vector<int>>& grid, int i, int j, int color, int newColor) {
		int n = grid.size(), m = grid[0].size();
		if (!isValid(n, m, i, j) || visited[i][j] || grid[i][j] != color)
			return;

		visited[i][j] = true;

		if ((i == 0 || j == 0 || i >= n - 1 || j >= m - 1)
			|| (i + 1 <= n - 1 && grid[i + 1][j] != color && !visited[i + 1][j])
			|| (i - 1 >= 0 && grid[i - 1][j] != color && !visited[i - 1][j])
			|| (j + 1 <= m - 1 && grid[i][j + 1] != color && !visited[i][j + 1])
			|| (j - 1 >= 0 && grid[i][j - 1] != color && !visited[i][j - 1]))
			grid[i][j] = newColor;

		for (int d = 0; d < 4; d++)
			dfs(grid, dr[d] + i, dc[d] + j, color, newColor);
	}
};

class Solution3 {
private:
	const int dr[4]{ -1, 0, 1, 0 };
	const int dc[4]{ 0, 1, 0, -1 };

	bool isIsland;

	vector<vector<bool>> visited;

	bool isValid(int R, int C, int i, int j) {
		return i >= 0 && j >= 0 && i < R && j < C;
	}

	bool isGridBoundry(int n, int m, int i, int j) {
		return i == 0 || i == n || j == 0 || j == m;
	}

public:
	int closedIsland(vector<vector<int>>& grid) {
		visited.resize(grid.size(), vector<bool>(grid[0].size()));

		int count{};
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (!grid[i][j]) {
					isIsland = true;
					dfs(grid, i, j);
					count += isIsland;
				}
			}
		}
		return count;
	}

	void dfs(vector<vector<int>>& grid, int i, int j) {
		int n = grid.size(), m = grid[0].size();
		if (!isValid(n, m, i, j) || visited[i][j] || grid[i][j])
			return;

		visited[i][j] = true;

		for (int d = 0; d < 4; d++)
			if (isGridBoundry(n, m, dr[d] + i, dc[d] + j)) {
				isIsland = false;
				return;
			}

		for (int d = 0; d < 4; d++)
			dfs(grid, dr[d] + i, dc[d] + j);
	}
};

class Solution {
private:
	const int dr[4]{ -1, 0, 1, 0 };
	const int dc[4]{ 0, 1, 0, -1 };

	bool isCyclic = false;

	vector<vector<bool>> visited;

	bool isValid(int R, int C, int i, int j) {
		return i >= 0 && j >= 0 && i < R && j < C;
	}

public:
	bool containsCycle(vector<vector<char>>& grid) {
		visited.resize(grid.size(), vector<bool>(grid[0].size()));

		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (!visited[i][j])
					dfs(grid, grid[i][j], i, j, -1, -1);

				if (isCyclic)
					return true;
			}
		}
		return false;
	}

	void dfs(vector<vector<char>>& grid, char oldLetter, int i, int j, int oldI, int oldJ) {
		if (!isValid(grid.size(), grid[0].size(), i, j)
			|| grid[i][j] != oldLetter || isCyclic)
			return;

		if (visited[i][j]) {
			isCyclic = true;
			return;
		}

		visited[i][j] = true;

		for (int d = 0; d < 4; d++)
		{
			int ni = i + dr[d], nj = j + dc[d];

			if (ni == oldI && nj == oldJ) // Don't go back to your parent
				continue;

			dfs(grid, grid[i][j], ni, nj, i, j);
		}
	}
};

int main()
{
	return 0;
}