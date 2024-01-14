#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = (int)1e6;
const int MOD = (int)1e9 + 7;
vector<int> nums = {1, 2, 3, 4, 5, 6};
int dp[MAX_N + 1];

int f(int n)
{
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    int cnt = 0;
    for (int i = 0; i <= 5; i++)
    {
        if (n - nums[i] >= 0)
        {
            cnt = (cnt + f(n - nums[i])) % MOD;
        }
    }
    return dp[n] = cnt % MOD;
}

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << f(n) << "\n";
    return 0;
}