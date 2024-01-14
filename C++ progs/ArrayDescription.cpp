#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = (int)1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    // dp[i][v] = number of ways to fill up the array till index 0 when arr[i] = v;

    // For i = 0 -> number of ways depends on the value of arr[0]
    // if arr[0] = 0 -> any number can be filled up so dp[0][1] -> dp[0][m] = 1
    // if arr[0] = v -> only one number can be filled up so dp[0][v] = 1 others are zero

    if (arr[0] == 0)
        fill(dp[0].begin(), dp[0].end(), 1);
    else
        dp[0][arr[0]] = 1;

    // For the index > 0 the number of ways depend on the value of the previous index
    // For dp[i][v] = dp[i - 1][v - 1] + dp[i - 1][v] + dp[i - 1][v + 1];

    for (ll i = 1; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (ll v = 1; v <= m; v++)
            {
                for (ll k : {v - 1, v, v + 1})
                {
                    if (k >= 1 and k <= m)
                    {
                        (dp[i][v] += dp[i - 1][k]) %= mod;
                    }
                }
                // dp[i][v] %= mod;
            }
        }
        else
        {
            for (ll k : {arr[i] - 1, arr[i], arr[i] + 1})
            {
                if (k >= 1 and k <= m)
                {
                    (dp[i][arr[i]] += dp[i - 1][k]) %= mod;
                }
            }
            // dp[i][arr[i]] %= mod;
        }
    }
    ll ans = 0;
    for (ll v = 1; v <= m; v++)
        ans = (ans + dp[n - 1][v]) % mod;
    cout << ans << "\n";
    return 0;
}