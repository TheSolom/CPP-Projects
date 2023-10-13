#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<int> vec(26);

    for (int i = 0; i < s.length(); i++)
    {
        vec[s[i] - 'a']++;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (vec[s[i] - 'a'] > 0)
        {
            cout << s[i] << " : " << vec[s[i] - 'a'] << "\n";

            vec[s[i] - 'a'] = 0;
        }
    }
}