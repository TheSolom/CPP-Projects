#include <iostream>
#include <bitset>
using namespace std;


int main()
{
    int n, cntr = 0;
    cin >> n;

    while (n)
    {
        if (n & 1)
            cntr++;

        n >>= 1;
    }

    cout << cntr;


    //int x, cntr = 0;
    //cin >> x;

    //string binary = bitset<32>(x).to_string(); //to binary

    //for (int i = 0; i < binary.length(); i++)
    //{
    //    if (binary[i] == '1')
    //    {
    //        cntr++;
    //    }
    //}

    //cout << cntr;
}