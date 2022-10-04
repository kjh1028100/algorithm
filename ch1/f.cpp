#include <bits/stdc++.h>
using namespace std;
string s, result;
int a[56];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
        int a = (int)s[i];
        int temp = a + 13;
        // 대문자
        if (a >= 65 && a <= 90)
        {
            if (temp > 90)
                result += (char)(temp - 26);
            else
                result += (char)temp;
        }
        // 소문자
        else if (a >= 97 && a <= 122)
        {
            if (temp > 122)
                result += (char)(temp - 26);
            else
                result += (char)temp;
        }
        else
            result += (char)a;
    }
    cout << result << "\n";
    return 0;
}