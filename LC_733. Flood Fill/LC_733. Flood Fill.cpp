#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
	vector<vector<bool>> visited;

public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
		visited.resize(image.size(), vector<bool>(image[0].size()));
		dfs(image, sr, sc, image[sr][sc], color);
		return image;
	}

	void dfs(vector<vector<int>>& image, int r, int c, int color, int newColor) {
		if (!isNeighbor(image, r, c) || visited[r][c] || image[r][c] != color)
			return;

		visited[r][c] = true, image[r][c] = newColor;

		dfs(image, r - 1, c, color, newColor);
		dfs(image, r + 1, c, color, newColor);
		dfs(image, r, c - 1, color, newColor);
		dfs(image, r, c + 1, color, newColor);
	}

	bool isNeighbor(vector<vector<int>>& image, int r, int c) {
		if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size())
			return false;
		return true;
	}
};

int main()
{
	return 0;
}