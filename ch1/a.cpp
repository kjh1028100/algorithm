#include <bits/stdc++.h>
using namespace std;
int a[9], n, sum;
pair<int, int> p;
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 9; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = i; j < 9; j++)
        {
            if (sum - a[i] - a[j] == 100)
            {
                p.first = a[i];
                p.second = a[j];
                break;
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (p.first == a[i] || p.second == a[i])
            continue;
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    for (int k : v)
        cout << k << "\n";
    return 0;
}