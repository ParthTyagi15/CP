#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = (int)1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    ll sum = (n * (n + 1)) / 2;
    if (sum % 2 != 0)
    {
        cout << 0 << endl;
        return;
    }   
    sum = sum / 2;
    // dp[i][x] = number of ways to sum x from 1....i
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int x = 0; x <= sum; x++)
        {

            dp[i][x] = dp[i - 1][x];
            if (x - i >= 0)
            {
                dp[i][x] = (dp[i][x] + dp[i - 1][x - i]) % mod;
            }
        }
    }
    cout << dp[n - 1][sum]<< "\n";
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
