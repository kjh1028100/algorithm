// 범위안에 있으면 ++
#include <bits/stdc++.h>
using namespace std;
int a, b, c, d[104], s, e, result;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c;
    for (int i = 0; i < 3; i++)
    {
        cin >> s >> e;
        for (int j = s; j < e; j++)
            d[j]++;
    }
    for (int i = 1; i < 100; i++)
    {
        switch (d[i])
        {
        case 3:
            result += 3 * c;
            break;
        case 2:
            result += 2 * b;
            break;
        case 1:
            result += 1 * a;
            break;
        }
    }
    cout << result << "\n";
    return 0;
}