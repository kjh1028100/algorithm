#include <bits/stdc++.h>
using namespace std;
string a, s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    a = s;
    reverse(s.begin(), s.end());
    if (a == s)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
    return 0;
}