#include <iostream>
using namespace std;

int main()
{
    char n[2];
    cin >> n[0] >> n[1];

    int cntr1(0), cntr2(0);

    if (n[0] == '0')
        cntr1 += 2;
    else if (n[0] == '1')
        cntr1 += 7;
    else if (n[0] == '2')
        cntr1 += 2;
    else if (n[0] == '3')
        cntr1 += 3;
    else if (n[0] == '4')
        cntr1 += 3;
    else if (n[0] == '5')
        cntr1 += 4;
    else if (n[0] == '6')
        cntr1 += 2;
    else if (n[0] == '7')
        cntr1 += 5;
    else if (n[0] == '8')
        cntr1 += 1;
    else if (n[0] == '9')
        cntr1 += 2;

    if (n[1] == '0')
        cntr2 += 2;
    else if (n[1] == '1')
        cntr2 += 7;
    else if (n[1] == '2')
        cntr2 += 2;
    else if (n[1] == '3')
        cntr2 += 3;
    else if (n[1] == '4')
        cntr2 += 3;
    else if (n[1] == '5')
        cntr2 += 4;
    else if (n[1] == '6')
        cntr2 += 2;
    else if (n[1] == '7')
        cntr2 += 5;
    else if (n[1] == '8')
        cntr2 += 1;
    else if (n[1] == '9')
        cntr2 += 2;

    cout << cntr1 * cntr2;
}