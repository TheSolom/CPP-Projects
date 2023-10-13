#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    long long graph[5001][5001]{};

    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                graph[i][j] = 0;          
            else
                cin >> graph[i][j];
        }

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
            graph[i][j] += graph[i][j - 1];

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
            graph[j][i] += graph[j - 1][i];

    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << graph[x2][y2] - graph[x2][y1 - 1] - graph[x1 - 1][y2] + graph[x1 - 1][y1 - 1] << "\n";
    }
}