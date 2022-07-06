#include <iostream>
using namespace std;
using ll = long long;

bool HasSquareRoot(ll n) {

    double num = sqrt(n);
    if (num - (int)num <= 0)
        return true;
    else
        return false;
}


int main()
{
    ll n;
    while (true) {
        cin >> n;
        if (n == 0)
            return 0;

        if (!HasSquareRoot(n))
            cout << "no\n";
        else
            cout << "yes\n";
    }
}