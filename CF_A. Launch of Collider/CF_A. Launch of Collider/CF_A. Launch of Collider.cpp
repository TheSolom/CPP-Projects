#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int n;  cin >> n;
    string s;   cin >> s;

    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int time = numeric_limits<int>::max(); //or INT_MAX 
    bool flag = false;
    for (int i = 0; i < n-1; i++)
    {
        int cntr = 0;
        if (s[i] == 'R' && s[i + 1] == 'L')
        {
            while (true) // or instead of while loop use min(time, (arr[i]-arr[i+1]/2));
            {
                ++arr[i];
                --arr[i + 1];
                ++cntr;
                if (arr[i] == arr[i + 1])
                {
                    if (time > cntr)
                    {
                        time = cntr;
                        flag = true;
                    }
                    break;
                }
            }
        }
    }

    if (flag)
        cout << time;
    else
    cout << "-1";
}