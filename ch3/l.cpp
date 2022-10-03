#include <bits/stdc++.h>
using namespace std;
#define prev aaa
#define next aaaa
int r, c, prev[34], ret;
char a[24][24];
bool visited[34];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

void go(int y, int x, int cnt)
{
    ret = max(ret, cnt);
    for (int i = 0; i < 4; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 0 || cy < 0 || cx >= c || cy >= r)
            continue;
        int next = (int)(a[cy][cx] - 'A');
        if (visited[next] == 0)
        {
            visited[next] = 1;
            cnt++;
            go(cy, cx, cnt);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    int next = (int)(a[0][0] - 'A');
    visited[next] = 1;
    go(0, 0, 1);
    cout << ret << "\n";
    return 0;
}