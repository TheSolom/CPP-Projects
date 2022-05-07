#include <iostream>
using namespace std;

int path_sum(int grid[100][100], int row, int col, int ROWS, int COLS, int cntr)
{
    if (row == ROWS && col == COLS)
    {
        return cntr;
    }
    else if (row = ROWS)
    {
        return cntr + path_sum(grid, row, col + 1, ROWS, COLS, cntr);
    }
    else
    {
        return cntr + path_sum(grid, row + 1, col, ROWS, COLS, cntr);
    }


    if (grid[row + 1][col] > grid[row][col + 1] && grid[row + 1][col] > grid[row + 1][col + 1])
    {
        return cntr + path_sum(grid, row, col + 1, ROWS, COLS, cntr);
    }
    else if (grid[row][col + 1] > grid[row + 1][col] && grid[row][col + 1] > grid[row + 1][col + 1])
    {
        return cntr + path_sum(grid, row + 1, col, ROWS, COLS, cntr);
    }
    else
    {
        return cntr + path_sum(grid, row + 1, col + 1, ROWS, COLS, cntr);
    }
}

int main()
{
    int grid[100][100], n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    cout << path_sum(grid, 0, 0, 2, 2, grid[0][0]) << endl;
}