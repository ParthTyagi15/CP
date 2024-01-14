#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxN = 1e5;


void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int>h(n),dp(n,1e9);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    // memset(dp, 1000000000, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        // dp[i] = h[i];
        for (int j = i + 1; j <= i + k; j++)
        {
            if (j < n)
            {
                dp[j] = min(dp[j], dp[i] + abs(h[j] - h[i]));
            }
        }
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
