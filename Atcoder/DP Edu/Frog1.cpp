#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxN = 1e5;

int h[maxN + 1];
int dp[maxN + 1];

void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> h[i];
    dp[0] = 0;

    for(int i = 1; i < n; i++){
        if(i > 1)
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
        else
        dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
    }
    cout << dp[n - 1] << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
