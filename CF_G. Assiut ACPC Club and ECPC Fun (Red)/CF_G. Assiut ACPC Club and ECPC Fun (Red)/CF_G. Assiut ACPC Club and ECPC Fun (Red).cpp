#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> vec[i];

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        vec[l] = vec[r] = -1;
    }

    bool flag = false;
    vector<int> vec2;
    for (int i = 1; i <= n; i++)
    {
        if (vec[i] == -1 && !flag)
        {
            flag = true;
        }
        else if (vec[i] == -1 && flag)
        {
            flag = false;
        }
        else if (!flag)
        {
            vec2.push_back(vec[i]);
        }
    }

    cout << vec2.size() << " ";
    for (int i = 0; i < vec2.size(); i++)
        cout << vec2[i] << " ";
}