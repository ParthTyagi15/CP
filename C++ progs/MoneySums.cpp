#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<bool>> dp(n + 1, vector<bool>(1000 * n + 1, false));
    // dp[i][x] = true if it is possible to make x using the first i coins, false otherwise.
    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int x = 0; x <= 1000 * n; x++)
        {
            dp[i][x] = dp[i - 1][x];
            if (x - v[i - 1] >= 0 and dp[i - 1][x - v[i - 1]])
                dp[i][x] = true;
        }
    }
    vector<int> ans;
    for (int x = 1; x <= 1000 * n; x++)
    {
        if (dp[n][x])
        {
            ans.push_back(x);
        }
    }
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}