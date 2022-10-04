#include <bits/stdc++.h>
using namespace std;
#define prev aaa
int n, k, prev[100004], a, ret;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        prev[i] = prev[i - 1] + a;
    }
    for (int i = k; i < n; i++)
    {
        ret = max(ret, prev[i] - prev[i - k]);
    }
    cout << ret;
    return 0;
}