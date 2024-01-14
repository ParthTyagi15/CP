#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxX = (int)1e6;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> dp(n + 1, 1e9);
    // dp[x] = minimum number of operations to go from x to zero.
    dp[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (char c : to_string(i))
        {
            dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}