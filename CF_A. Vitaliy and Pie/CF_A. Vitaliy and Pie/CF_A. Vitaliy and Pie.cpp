#include <iostream>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int need = 0, keys[123]{};

    for (int i = 0; i < 2*n-2; i++)
    {
        if (s[i] >= 97)
        {
            keys[s[i]]++;
        }
        else
        {
            if (keys[s[i] + 32] > 0)
            {
                keys[s[i] + 32]--;
            }
            else
            {
                need++;
            }
        }
    }

    cout << need;
}