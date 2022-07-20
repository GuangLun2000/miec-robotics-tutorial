#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Reformat the string.
// You are given an alphanumeric string s.
// That is, no two adjacent characters have the same type.

string reformat(string s)
{
    vector<char> n, c;
    string ans;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            n.push_back(s[i]);
        else
            c.push_back(s[i]);
    }

    // size()返回值类型 unsigned int, 减法为负数，会造成溢出
    // by Hanlin Cai 20122161 832002117
    int ns = n.size(), cs = c.size();
    if ((cs - ns > 1) || (ns - cs > 1))
        return "";
    if (ns >= cs)
    {
        for (int i = 0; i < cs; i++)
        {
            ans += n[i];
            ans += c[i];
        }
        if (ns > cs)
            ans += n[ns - 1];
    }
    else
    {
        for (int i = 0; i < ns; i++)
        {
            ans += c[i];
            ans += n[i];
        }
        ans += c[cs - 1];
    }
    return ans;
}

int main()
{
    cout << "Please enter the string: ";
    // char str[] = "abcdeeeee";
    // char str[] = "";
    // cin >> str;
    string str = "";
    cin >> str;
    string res = reformat(str);
    cout << "The returned string is: " << res << endl;
}
// Experiment 10 - 5
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117