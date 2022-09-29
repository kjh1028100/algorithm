#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int n, m, x1, y1, x2, y2;
int visited[301][301];
char a[301][301];
queue<int> q;
int main()
{
    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--, x1--, y2--, x2--;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
    }
    q.push(1000 * y1 + x1);
    visited[y1][x1] = 1;
    int cnt = 0;
    while (a[y2][x1] != '0')
    {
        cnt++;
        queue<int> temp;
        while (q.size())
        {
            int y = q.front() / 1000;
            int x = q.front() % 1000;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int cx = x + dx[i];
                int cy = y + dy[i];
                if (cx < 0 || cy < 0 || cy >= n || cx >= m || visited[cy][cx])
                    continue;
                visited[cy][cx] = cnt;
                if (a[cy][cx] != '0')
                {
                    a[cy][cx] = '0';
                    temp.push(1000 * cy + cx);
                }
                else
                    q.push(1000 * cy + cx);
            }
        }
        q = temp;
    }
    cout << visited[y2][x2] << "\n";
    return 0;
}