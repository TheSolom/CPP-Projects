#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    map<char, int> mp;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
            mp[str[i]]++;
    }

    string s;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            continue;

        if (mp[s[i]] > 0)
        {
            mp[s[i]]--;
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}