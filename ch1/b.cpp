// 아스키코드
#include <bits/stdc++.h>
using namespace std;
int a[26];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        a[s[i] - 'a']++;
    }
    // for (char i = 'a'; i < 'z'; i++)
    //     cout << a[i - 'a'] << " ";
    for (int i = 0; i < 26; i++)
        cout << a[i] << " ";

    return 0;
}