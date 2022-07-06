#include <iostream>
using namespace std;

int remove0(int n)
{
    int New = 0, ten = 1;
    while (n != 0)
    {
        int digit = n % 10;
        
        if (digit != 0)
        {
            New += digit * ten;
            ten *= 10;
        }

        n /= 10;
    }

    return New;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int C = remove0(a + b);

    int newA = remove0(a);
    int newB = remove0(b);

    cout << (newA + newB == C ? "YES" : "NO") << endl;
}