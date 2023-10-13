#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n, m;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    set<int> set;
    char x;
    cin >> m;
    while (m--)
    {
        cin >> x;
        if (x == 'L')
        {
            set.insert(vec.front());
            vec.erase(vec.begin());
        }
        else if (x == 'R')
        {
            set.insert(vec.back());
            vec.pop_back();
        }
        else
        {
            auto it = set.end();
            --it;
            cout << *it << "\n";
            set.erase(it);
        }
    }
}