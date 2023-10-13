#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> vec(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> vec[i];

    while (q--)
    {
        string s;
        cin >> s;

        if (s == "pop_back")
            vec.pop_back();
        else if (s == "front")
            cout << vec[1] << "\n";
        else if (s == "back")
            cout << vec[vec.size() - 1] << "\n";
        else if (s == "sort")
        {
            int l, r;
            cin >> l >> r;
            sort(vec.begin() + l, vec.begin() + r + 1);
        }
        else if (s == "reverse")
        {
            int l, r;
            cin >> l >> r;
            reverse(vec.begin() + l, vec.begin() + r + 1);
        }
        else if (s == "print")
        {
            int pos;
            cin >> pos;
            cout << vec[pos] << "\n";
        }
        else if (s == "push_back")
        {
            int x;
            cin >> x;
            vec.push_back(x);
        }
    }
}