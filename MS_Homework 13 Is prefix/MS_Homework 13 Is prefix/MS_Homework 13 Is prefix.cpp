#include <iostream>
using namespace std;

bool is_prefix(string s, string sub, int i = 0)
{
    if (i == sub.length())
        return true;
    
    if (s[i] != sub[i])
        return false;

    return is_prefix(s, sub, i + 1);
}

int main()
{
    string s, sub;
    cin >> s >> sub;

    cout << is_prefix(s, sub) << endl;
}
