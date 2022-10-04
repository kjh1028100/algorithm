#include <bits/stdc++.h>
using namespace std;
bool flag;
int n, a[27];
string s, result;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        a[s[0] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (a[i] >= 5)
        {
            result += (char)(i + 97);
            flag = 1;
        }
    }
    if (flag)
        cout << result;
    else
        cout << "PREDAJA";
    return 0;
}