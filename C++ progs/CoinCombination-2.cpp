#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_X = (int)1e6;
const ll MOD = (int)1e9 + 7;
const int MAX_N = 100;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n, 0);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j]; // not pick
            if (j - c[i - 1] >= 0)
            {
                dp[i][j] = (dp[i][j] + dp[i][j - c[i - 1]]) % MOD;
            }
        }
    }
    cout << dp[n][x] << "\n";
    return 0;
}
