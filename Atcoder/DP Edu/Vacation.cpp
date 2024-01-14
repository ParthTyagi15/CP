#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = v[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = v[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = v[i][2] + max(dp[i - 1][1], dp[i - 1][0]);
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
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
