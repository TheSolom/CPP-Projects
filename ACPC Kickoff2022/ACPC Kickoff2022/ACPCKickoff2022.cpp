#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

int main()
{    
    /*long long low = 1, high = 1000000001;

    char ch;
    while (low <= high)
    {
        long long x = low + (high - low) / 2;
        cout << x << endl;

        cin >> ch;
        if (ch == '<')
        {
            high = x - 1;
        }
        else if (ch == '>')
        {
            low = x + 1;
        }
        else
        {
            cout << "! " << x << endl;
            fflush(stdout);
            return 0;
        }
    }*/

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector <string> vec;
        vec.resize(n);
        int* arr = new int[n];

        bool vis[1000001]{};
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i] >> arr[i];
            vis[i] = true;
        }

        for (int i = 0; i < n; i++)
        {
            if (true)
            {

            }

        }

        cout << endl;
    }
}