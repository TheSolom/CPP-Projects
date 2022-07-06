#include <iostream>
using namespace std;

int main()
{
    string str, final_string = "";
    int n;
    cin >> str >> n;
    
    string s1; cin >> s1;
    bool flag = false;

    if (s1.substr(0, str.length()) == str)
    {
        final_string = s1;
        flag = true;
    }

    string s2;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> s2;
        if (s2.substr(0, str.length()) == str)
        {
            if (s2 < final_string || final_string == "")
            {
                final_string = s2;
                flag = true;
            }    
        }
    }

    if (!flag)
        cout << str;
    else
        cout << final_string << endl;
}