#include <bits/stdc++.h>
using namespace std;
int n;
string s, name;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> s;
    int a = s.find('*');
    string pre = s.substr(0, a);
    string next = s.substr(a + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        if (pre.size() + next.size() > name.size())
            cout << "NE"
                 << "\n";
        else
        {
            if (name.substr(0, pre.size()) == pre && name.substr(name.size() - next.size()) == next)
                cout << "DA"
                     << "\n";
            else
                cout << "NE"
                     << "\n";
        }
    }
    return 0;
}