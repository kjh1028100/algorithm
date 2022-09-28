#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int r, c, sx, sy, fire_visited[1004][1004], perseon_visited[1004][1004], ret, y, x;
char a[1004][1004];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
bool in(int a, int b)
{
    return 0 <= a && a < r && 0 <= b && b < c;
}
int main()
{
    queue<pair<int, int>> q;
    cin >> r >> c;
    fill(&fire_visited[0][0], &fire_visited[0][0] + 1004 * 1004, INF);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
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
            if (!in(cy, cx))
                continue;
            if (fire_visited[cy][cx] != INF || a[cy][cx] == '#')
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
        if (x == c - 1 || y == r - 1 || x == 0 || y == 0)
        {
            ret = perseon_visited[y][x];
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (!in(cy, cx))
                continue;
            if (perseon_visited[cy][cx] || a[cy][cx] == '#')
                continue;
            if (fire_visited[cy][cx] <= 1 + perseon_visited[y][x])
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