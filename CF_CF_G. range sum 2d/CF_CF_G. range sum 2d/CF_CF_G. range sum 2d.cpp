#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> graph(n + 1, vector<long long>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> graph[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            graph[i][j] += graph[i][j - 1];

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            graph[j][i] += graph[j - 1][i];

    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << graph[x2][y2] - graph[x2][y1 - 1] - graph[x1 - 1][y2] + graph[x1 - 1][y1 - 1] << "\n";
    }
}