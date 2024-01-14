#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxX = (int)1e6;
const int MOD = (int)1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    // dp[r][c] = number of ways to reach r,c
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++)
        {
            if (row[j] == '.')
            {
                if (i > 0)
                {
                    (dp[i][j] += dp[i - 1][j]) %= MOD;
                }
                if (j > 0)
                {
                    (dp[i][j] += dp[i][j - 1]) %= MOD;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    cout << dp[n - 1][n - 1] << "\n";

    return 0;
}