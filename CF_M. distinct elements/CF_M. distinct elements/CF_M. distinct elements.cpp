#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    set<int> set;
    for (int i = 0; i < n; i++)
    {
        int ai;
        cin >> ai;
        set.insert(ai);
    }

    for (int i = 0; i < set.size(); i++)
    {
        int x; 
        cin >> x;
        
        int idx = 1, pos = -1;
        for (auto it : set) 
        {
            if (it == x)
                pos = idx;
            idx++;
        }

        cout << pos - 1 << " " << set.size() - pos << "\n";
    }
}