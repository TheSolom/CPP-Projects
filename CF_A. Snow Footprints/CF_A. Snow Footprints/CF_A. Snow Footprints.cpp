#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int first = 0, final = 0, flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '.' && flag == 0)
        {
            first = i + 1;
            flag = 1;
        }

        if (s[i] == '.' && flag == 1)
        {
            final = i;
            break;
        }
    }

    int rem = first - 1;
    if (rem <= -1)
    {
        rem = 0;
    }

    cout << final - first << " " << (final - first + 1) / 2 + rem;
}