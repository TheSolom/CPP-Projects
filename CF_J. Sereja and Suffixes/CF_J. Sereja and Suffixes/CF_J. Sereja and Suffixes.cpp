#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> vec(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> vec[i];

/*
      1 2 3 4 1 2 3 4 10 99  vec
      1 1 1 1 1 1 1 1  1  1  d[i]
      6 6 6 6 6 5 4 3  2  1  d[i - 1] += d[i] 
*/

    vector<bool> vis(100001, false);
    vector<int> d(100001, 0);

    for (int i = n; i > 0; i--)
    {
        if (vis[vec[i]] == false)
        {
            d[i]++;
            vis[vec[i]] = true;
        }
    }

    for (int i = n; i > 1; i--)
    {
        d[i - 1] += d[i];
    }

    int l;
    for (int i = 0; i < m; i++)
    {       
        cin >> l;
        cout << d[l] << "\n";
    }
}