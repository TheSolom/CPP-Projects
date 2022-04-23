#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
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

    int* count_ = max_element(max, max + 1001);

    if (n - *count_ >= *count_ - 1)
        cout << "YES";
    else
        cout << "NO";
}