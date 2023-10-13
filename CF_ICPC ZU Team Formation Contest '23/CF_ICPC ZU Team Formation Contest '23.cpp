#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
    
int main()
{
    string s;
    cin >> s;

    map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }

    bool flag = false;
    for (auto x : mp)
    {
        if (x.second != 2)
        {
            flag = true;
            break;
        }
    }

    if (flag)
    {
        cout << "No";
    }
    else
        cout << "Yes";
}