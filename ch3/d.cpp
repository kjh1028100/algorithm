#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, r, x, y, sx, sy, perseon_visited[1004][1004], fire_visited[1004][1004], ret;
char a[1004][1004];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int main()
{
    cin >> n >> r;
    queue<pair<int, int>> q;
    memset(&fire_visited, INF, sizeof(fire_visited));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'F')
            {
                fire_visited[i][j] = 1;
                q.push({i, j});
            }
            else if (a[i][j] == 'J')
            {
                sy = i;
                sx = j;
            }
        }
    }
    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx < 0 || cy < 0 || cx >= r || cy >= n)
                continue;
            if (a[cy][cx] == '#' || fire_visited[cy][cx] != INF)
                continue;
            fire_visited[cy][cx] = 1 + fire_visited[y][x];
            q.push({cy, cx});
        }
    }
    perseon_visited[sy][sx] = 1;
    q.push({sy, sx});
    while (q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (y == n - 1 || x == r - 1 || x == 0 || y == 0)
        {
            ret = perseon_visited[y][x];
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx < 0 || cy < 0 || cx >= r || cy >= n)
                continue;
            if (a[cy][cx] == '#' || perseon_visited[cy][cx])
                continue;
            if (fire_visited[cy][cx] <= perseon_visited[y][x] + 1)
                continue;
            perseon_visited[cy][cx] = 1 + perseon_visited[y][x];
            q.push({cy, cx});
        }
    }
    if (ret != 0)
        cout << ret << "\n";
    else
        cout << "IMPOSSIBLE"
             << "\n";
    return 0;
}