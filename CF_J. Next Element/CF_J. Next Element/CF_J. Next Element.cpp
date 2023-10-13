#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, x;
    cin >> n;

    vector<int> vec(n + 1);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    stack<int>st;
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && vec[st.top()] < vec[i])
        {
            vec[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()) 
    {
        vec[st.top()] = -1;
        st.pop();
    }

    cin >> q;
    while (q--)
    {
        cin >> x;
        cout << vec[x - 1] << "\n";
    }
}