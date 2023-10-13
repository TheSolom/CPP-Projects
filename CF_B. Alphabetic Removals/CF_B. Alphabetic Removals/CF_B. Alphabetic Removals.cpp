#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int arr[26]{};
    for (int i = 0; i < s.length(); i++)
        arr[s[i] - 'a']++;

    for (int i = 'a'; i <= 'z'; i++)
    {
        if (k == 0)
            break;

        if (arr[i - 'a'] > 0)
        {
            for (int j = 0; j < n; j++)
            {
                if (k == 0)
                    break;

                if (s[j] == i)
                {
                    s[j] = ' ';
                    k--;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
            continue;
        cout << s[i];
    }
}