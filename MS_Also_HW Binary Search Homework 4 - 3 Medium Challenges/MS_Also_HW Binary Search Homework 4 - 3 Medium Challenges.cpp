#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        double EPS = 1e-9, start = 0, end = x;

        while (end - start > EPS)
        {
            double mid = start + (end - start) / 2;
            if (mid * mid < x)
                start = mid;
            else
                end = mid;
        }

        return start + 1e-9;
    }
};

int main()
{
    Solution ss;
    cout << ss.mySqrt(8);
}