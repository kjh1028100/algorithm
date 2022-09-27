#include <bits/stdc++.h>
using namespace std;
int n, m, visited[54][54], ret;
char a[54][54];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

void bfs(int y, int x)
{
    memset(&visited, 0, sizeof(visited));
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx < 0 || cy < 0 || cx >= m || cy >= n || visited[cy][cx])
                continue;
            if (a[cy][cx] == 'W')
                continue;
            visited[cy][cx] = 1 + visited[y][x];
            q.push({cy, cx});
            ret = max(ret, visited[cy][cx]);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'L')
                bfs(i, j);
        }
    }
    cout << ret - 1 << "\n";
    return 0;
}