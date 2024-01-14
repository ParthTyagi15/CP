#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = (int)1e6;
const int MOD = (int)1e9 + 7;
vector<int> coins;
ll dp[MAX_N + 1];
int n, x;

int f(int amt)
{
    if (amt == 0)
        return 0;
    if (dp[amt] != -1)
        return dp[amt];

    int cnt = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (amt - coins[i] >= 0)
        {
            cnt = min(cnt, f(amt - coins[i]) + 1);
        }
    }
    return dp[amt] = cnt;
}

int main()
{
    cin >> n >> x;
    coins.resize(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    memset(dp, -1, sizeof(dp));
    if (f(x) == 1e9)
        cout << -1 << "\n";
    else
        cout << f(x) << "\n";
    return 0;
}