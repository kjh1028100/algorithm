#include <bits/stdc++.h>
using namespace std;
#define prev aaa
#define next aaaa
const int max_v = 200004;
int n, m, prev[max_v], visited[max_v], ret;
vector<int> v;
queue<int> q;
int main()
{
    cin >> n >> m;
    visited[n] = 1;
    q.push(n);
    while (q.size())
    {
        int here = q.front();
        q.pop();
        if (here == m)
        {
            ret = visited[m] - 1;
            break;
        }
        for (int next : {here - 1, here + 1, here * 2})
        {
            if (next < 0 || next >= max_v || visited[next])
                continue;
            visited[next] = 1 + visited[here];
            prev[next] = here;
            q.push(next);
        }
    }
    for (int i = m; i != n; i = prev[i])
        v.push_back(i);
    v.push_back(n);
    reverse(v.begin(), v.end());
    cout << ret << "\n";
    for (int a : v)
        cout << a << " ";
    return 0;
}