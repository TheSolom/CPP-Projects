#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int q;
    cin >> q;

    while (q--)
    {
        int l, r, occ = 0;
        cin >> l >> r;

        for (int i = l - 1; i < r; i++)
        {
            if (s[i] == 'a')
            {
                occ++;
            }
        }
        cout << occ << "\n";
    }
}