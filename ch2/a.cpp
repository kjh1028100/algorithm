#include <bits/stdc++.h>
using namespace std;
int r, c, a[104][104], visited[104][104], y, x;
queue<pair<int, int>> q;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int main()
{
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
            scanf("%1d", &a[i][j]);
    }
    visited[1][1] = 1;
    q.push({1, 1});
    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx < 0 || cy < 0 || cx >= c || cy >= r || visited[cy][cx])
                continue;
            if (a[cy][cx] == 0)
                continue;
            visited[cy][cx] = 1 + visited[y][x];
            q.push({cy, cx});
        }
    }
    cout << visited[r][c] << "\n";
    return 0;
}