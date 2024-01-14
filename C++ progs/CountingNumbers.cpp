/*
Question: Your task is to count the number of integers between a
 and b
 where no two adjacent digits are the same.

 0≤a≤b≤10^18

 Input:
123 321

Output:
171

*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 20;
ll dp[MAX_N][10][2][2];

void reset()
{
    memset(dp, -1, sizeof(dp));
}

ll solve(string &number, int N, int prev, bool leading_zeroes, bool tight)
{
    if (N == 0)
        return 1;

    if (prev != -1 and dp[N][prev][leading_zeroes][tight] != -1)
        return dp[N][prev][leading_zeroes][tight];

    int limit = tight ? number[number.length() - N] - '0' : 9;
    ll ans = 0;

    for (int dig = 0; dig <= limit; dig++)
    {
        if ((dig == prev) and (leading_zeroes == 0))
            continue;
        
        ans += solve(number, N - 1, dig, (leading_zeroes & (dig == 0)), tight & (dig == limit));
    }
    return dp[N][prev][leading_zeroes][tight] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    reset();

    ll a, b;
    cin >> a >> b;
    // if (a != 0)
    //     a--;
    // if (a == 0 and b == 0)
    // {
    //     cout << 1 << endl;
    //     return 0;
    // }
    string A = to_string(a - 1);
    string B = to_string(b);
    ll ans1 = solve(B, B.length(), -1, 1, 1);
    reset();
    ll ans2 = solve(A, A.length(), -1, 1, 1);
    cout << ans1 - ans2 << "\n";
    return 0;
}