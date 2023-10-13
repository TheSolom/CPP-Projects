#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    map<char, int> mp;

    for (int i = 0; i < s.length(); i++)
        mp[s[i]]++;
    
    for (auto& it : mp)
        cout << it.first << " " << it.second << "\n";
}