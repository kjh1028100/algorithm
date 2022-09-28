#include <bits/stdc++.h>
using namespace std;
int n, l, r, a[54][54], sum, cnt;
bool visited[54][54];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

void dfs(int y, int x, vector<pair<int, int>> &q)
{
    for (int i = 0; i < 4; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 0 || cy < 0 || cx >= n || cy >= n || visited[cy][cx])
            continue;
        if (abs(a[cy][cx] - a[y][x]) >= l && abs(a[cy][cx] - a[y][x]) <= r)
        {
            visited[cy][cx] = 1;
            q.push_back({cy, cx});
            sum += a[cy][cx];
            dfs(cy, cx, q);
        }
    }
}

int main()
{
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    vector<pair<int, int>> q;
    while (true)
    {
        bool flag = 0;
        memset(&visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                {
                    q.clear();
                    visited[i][j] = 1;
                    q.push_back({i, j});
                    sum = a[i][j];
                    dfs(i, j, q);
                    if (q.size() == 1)
                        continue;
                    for (pair<int, int> p : q)
                    {
                        a[p.first][p.second] = sum / q.size();
                        flag = 1;
                    }
                }
            }
        }
        if (!flag)
            break;
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}