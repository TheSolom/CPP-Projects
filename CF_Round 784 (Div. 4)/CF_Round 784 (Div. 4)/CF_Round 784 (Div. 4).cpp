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
using ll = long long;

int main()
{
    int t, n;
	cin >> t;
	while (t--)
	{
        int n, max[1001]{0};
        cin >> n;
        vector <int> vec;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            vec.push_back(temp);
            max[vec[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (max[i] >= 3)
            {
                cout << vec[i] << endl;
                break;
            }
        }
	}	
}