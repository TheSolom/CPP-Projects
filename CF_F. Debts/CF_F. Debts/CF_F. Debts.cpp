#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<long long> vec(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> vec[i];

    for (int i = 0; i < m; i++)
    {
        int from, to, val;
        cin >> from >> to >> val;
        vec[from] -= val;
        vec[to] += val;
    }

    for (int i = 1; i <= n; i++)
    {
        if (vec[i] < 0)
        {
            cout << "NO";
            return 0;
        }
    }
    
    cout << "YES";
}