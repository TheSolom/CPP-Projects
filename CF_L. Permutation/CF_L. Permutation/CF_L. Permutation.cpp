#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{ 
    //freopen("mex.in", "r", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> vec(n + 1);
        vector<int> freq(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> vec[i];
            freq[vec[i]]++;
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;

            int idx = 1;
            for (int i = l; i <= r; i++)
            {
                if (freq[idx] == vec[i])
                    idx++;
                else
                    cout << freq[idx] << "\n";
            }
        }
    }
}