#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> vec(n + 1, 0);

    while (q--)
    {
        int x1, x2;
        cin >> x1 >> x2;

        if (x1 == 1)
            vec[x2]++;
        else
            cout << vec[x2] << "\n";
    }
}