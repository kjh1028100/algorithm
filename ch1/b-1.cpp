#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
string s;
int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        m[s[i] - 'a']++;
    for (int i = 0; i < 26; i++)
        cout << m[i] << " ";
    return 0;
}