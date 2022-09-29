#include <bits/stdc++.h>
using namespace std;
const int max_v = 500000;
int a, b, visited[2][max_v + 4];
bool ok;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    if (a == b)
    {
        cout << 0 << "\n";
        return 0;
    }
    visited[0][a] = 1;
    queue<int> q;
    q.push(a);
    int turn = 1;
    while (q.size())
    {
        b += turn;
        if (b > max_v)
            break;
        if (visited[turn % 2][b])
        {
            ok = 1;
            break;
        }
        int qSize = q.size();
        for (int i = 0; i < qSize; i++)
        {
            int x = q.front();
            q.pop();
            for (int next : {x - 1, x + 1, 2 * x})
            {
                if (next < 0 || next > max_v || visited[turn % 2][next])
                    continue;
                visited[turn % 2][next] = visited[(turn + 1) % 2][x];
                if (next == b)
                {
                    ok = 1;
                    break;
                }
                q.push(next);
            }
            if (ok)
                break;
        }
        if (ok)
            break;
        turn++;
    }
    if (ok)
        cout << turn << "\n";
    else
        cout << -1 << "\n";
    return 0;
}