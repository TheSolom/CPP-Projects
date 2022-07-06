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
#include <iomanip>
using ll = long long;
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        double h, u, t;
        cin >> h >> u >> t;
        
        double d = sqrt(h*h + u*u);

        cout << fixed << setprecision(9) << d;
    }
}

//int main() //Pd
//{
//    int T;
//    cin >> T;
//    while (T--)
//    {
//        int n, s, t;
//        cin >> n >> s >> t;
//
//        bool flag = false;
//
//        int _max = max(s, t);
//        if (_max == s)
//            flag = true;
//
//        int _min = min(s, t);
//
//        int sum = 0, cntrs = 0, cntrt = 0;
//        while (sum < n)
//        {
//            if (n - sum > _max)
//            {
//                sum += _max;
//                cntrs++;
//            }
//            else
//            {
//                sum += _min;
//                cntrt++;
//            }
//        }
//
//        if (flag)
//             cout << cntrs << " " << cntrt << endl;
//        else
//            cout << cntrt << " " << cntrs << endl;
//    }
//}


/*int main() //Pc
{
    int T, n;
    cin >> T >> n;

    int* arr = new int[n + 1];
    int* sorted = new int[n + 1];

    for (int i = 1; i <= n; i++)
        cin >> sorted[i];

    for (int i = 1; i <= n; i++)
        arr[i] = sorted[i];

    sort(sorted, sorted + n + 1);

    int maxcntr = n, mincntr = 0;
    while (true)
    {
        int _max = sorted[maxcntr], _min = sorted[mincntr];

        auto itr = find(arr, arr + n + 1, _max);
        int d_max = distance(arr, itr);

        auto itr2 = find(arr, arr + n + 1, _min);
        int d_min = distance(arr, itr2);

        if (d_max + 1 <= ((n+2)/2) && d_min + 1 >= ((n + 2) / 2))
        {
            swap(arr[d_max + 1], arr[d_min + 1]);
            break;
        }
        else if (d_max + 1 <= ((n + 2) / 2))
        {
            mincntr++;
        }
        else if (d_min + 1 >= ((n + 2) / 2))
        {
            maxcntr--;
        }
        else
        {
            maxcntr--;
            mincntr++;
        }
    }

    int sum = 0;

    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    for (int i = 1; i <= n; i++)
        sum += (arr[i] * i);

    cout << sum << endl;

    delete[] arr;
    delete[] sorted;
}*/