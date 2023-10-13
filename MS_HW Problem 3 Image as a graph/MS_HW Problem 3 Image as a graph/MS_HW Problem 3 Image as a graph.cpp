#include <iostream>
#include <vector>
using namespace std;

struct nodes
{
    int node;
    vector <int> neighbors;
};

using GRAPH = vector <vector <nodes>>;

int R, C;

bool isValid(int nr, int nc, int rows, int cols) {
    return nr >= 0 && nr < rows && nc >= 0 && nc < cols;
}

void add_neighbors(GRAPH& graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            int r1 = i - 1, c1 = j,
                r2 = i, c2 = j - 1,
                r3 = i, c3 = j + 1,
                r4 = i + 1, c4 = j;

            if (isValid(r1, c1, R, C))
                graph[i][j].neighbors.push_back(graph[r1][c1].node);

            if (isValid(r2, c2, R, C))
                graph[i][j].neighbors.push_back(graph[r2][c2].node);

            if (isValid(r3, c3, R, C))
                graph[i][j].neighbors.push_back(graph[r3][c3].node);       

            if (isValid(r4, c4, R, C))
                graph[i][j].neighbors.push_back(graph[r4][c4].node);
        }
    }
}

void print_adjaceny_matrix(GRAPH& graph, int rows,int cols)
{
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << "Node " << graph[i][j].node << " has neighbors: ";
            for (const auto& it : graph[i][j].neighbors)
            {
                cout << it << " ";
            }
            cout << "\n";
        }
    }
}


int main()
{
    cin >> R >> C;
    
    GRAPH graph (R, vector<nodes>(C));

    int cntr = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            graph[i][j].node = cntr++;

    add_neighbors(graph);

    print_adjaceny_matrix(graph, R, C);
}