#include <iostream>
using namespace std;

bool isPrime(int val, int i = 2)
{
    if (i > val / 2)
        return true;

    if (val % i == 0)
        return false;

    return isPrime(val, i + 1);
}

int count_primes(int start, int end, int cntr = 0)
{
    if (end < start || end <= 1)
        return 0;

    if (isPrime(end))
        cntr++;

    return cntr + count_primes(start, end - 1);
}

int main()
{
    int start, end, cntr = 0;
    cin >> start >> end;

    cout << count_primes(start, end);
}