#include <bits/stdc++.h>
using namespace std;
string s;
int n, ret = -987654321;
vector<int> num;
vector<char> oper;

int opear(char op, int a, int b)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
}

void go(int here, int a)
{
    if (here == num.size() - 1)
    {
        ret = max(ret, a);
        return;
    }
    go(here + 1, opear(oper[here], a, num[here + 1]));
    if (here + 2 <= num.size() - 1)
    {
        int temp = opear(oper[here + 1], num[here + 1], num[here + 2]);
        go(here + 2, opear(oper[here], a, temp));
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 0)
            num.push_back(s[i] - '0');
        else
            oper.push_back(s[i]);
    }
    go(0, num[0]);
    cout << ret << "\n";
    return 0;
}