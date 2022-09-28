#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int n, m, visited[MAX + 4];
long long cnt[MAX + 4];
int main()
{
    cin >> n >> m;
    if (n == m)
    {
        puts("0");
        puts("1");
        return 0;
    }
    queue<int> q;
    visited[n] = 1;
    cnt[n] = 1;
    q.push(n);
    while (q.size())
    {
        int here = q.front();
        q.pop();
        for (int next : {here + 1, here - 1, 2 * here})
        {
            if (next >= 0 && next <= MAX)
            {
                if (!visited[next])
                {
                    q.push(next);
                    visited[next] = 1 + visited[here];
                    cnt[next] += cnt[here];
                }
                else if (visited[next] == 1 + visited[here])
                {
                    cnt[next] += cnt[here];
                }
            }
        }
    }
    cout << visited[m] - 1 << "\n";
    cout << cnt[m] << "\n";
    return 0;
}