#include <bits/stdc++.h>
using namespace std;
string name;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    getline(cin, name);
    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] >= 65 && name[i] <= 90)
        {
            if (name[i] + 13 > 90)
                name[i] = name[i] + 13 - 26;
            else
                name[i] = name[i] + 13;
        }
        else if (name[i] >= 97 && name[i] <= 122)
        {
            if (name[i] + 13 > 122)
                name[i] = name[i] + 13 - 26;
            else
                name[i] = name[i] + 13;
        }
        else
            name[i] = name[i];
        cout << name[i];
    }
}