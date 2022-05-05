#include <iostream>
using namespace std;

bool Is_Palindrome(char s[], int i, int j)
{   
    if (i >= j)
        return true;

    if (s[i] != s[j])
        return false;

    return Is_Palindrome(s, i + 1, j - 1);
}

bool Is_PalindromeV2(char s[], int end)
{
    if (end <= 0)
        return true;

    if (s[0] != s[end])
        return false;

    return Is_PalindromeV2(s + 1, end - 2);
}

int main()
{
    char s[] = {'a', 'b', 'b', 'a'};

    int len = sizeof(s) / sizeof(s[0]) - 1;

    //cout << Is_Palindrome(s, 0, len) << endl;
    cout << Is_PalindromeV2(s, len) << endl;
}