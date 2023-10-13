#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<pair<int,int>> vec;
    vector<bool> vis(101);

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        if (!vis[x])
        {
            vis[x] = true;
            vec.push_back({ x, i });
        }
    }

    if (vec.size() >= k)
    {
        cout << "YES\n";
        for (int i = 0; i < k; i++)
            cout << vec[i].second << " ";
    }
    else
        cout << "NO";
}