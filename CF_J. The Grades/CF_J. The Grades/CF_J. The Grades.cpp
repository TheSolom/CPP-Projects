#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct marks
{
    string name;
    int A, M, S, E;
    long long sum;

    void input() {
        cin >> name;
        cin >> A >> M >> S >> E;
        sum = A + M + S + E;
    }
};

bool cmp(marks& a, marks& b) {
    if (a.sum == b.sum)
        return a.name < b.name;

    return a.sum > b.sum;
}

int main()
{
    int n;
    cin >> n;

    vector<marks> vec(n);

    for (int i = 0; i < n; i++)
        vec[i].input();
    
    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        cout << vec[i].name << " " << vec[i].sum << " " << vec[i].A << " " << vec[i].M << " " << vec[i].S << " " << vec[i].E << "\n";
    }
}