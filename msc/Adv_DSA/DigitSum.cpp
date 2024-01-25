/*
Question: For a pair of integers a and b, the digit sum of the interval [a,b] is defined as the sum of all digits occurring in all numbers between
(and including) a and b. For example, the digit sum of [28, 31] can be calculated as:
2+8  +  2+9  +  3+0  +  3+1 = 28
Given the numbers a and b, calculate the digit sum of [a,b].
*/

// RECURSIVE FORMULA = dp[n][1] = sum(x = 0 -> x = limit)[x * C(x) + dp[n - 1][0]] + limit * C(limit) + dp[n - 1][1]

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 18;

ll cnt(string &R, int N, bool tight)
{
    if (tight == 0)
        return (pow(10, N) + 0.1);

    if (N == 0)
        return 1;

    ll ans = 0;
    int limit = (R[R.length() - N] - '0');
    for (int dig = 0; dig <= limit; dig++)
    {
        ans += cnt(R, N - 1, tight & (dig == limit));
    }
    return ans;
}

ll dp[MAX_N][2];

ll sum(string &R, int N, bool tight)
{
    if (N == 0)
        return 0;

    if (dp[N][tight] != -1)
        return dp[N][tight];

    int limit = 9;
    if (tight)
    {
        limit = R[R.length() - N] - '0';
    }

    ll total = 0;
    for (int dig = 0; dig <= limit; dig++)
    {
        total += (dig * cnt(R, N - 1, tight & (dig == limit)));
        total += sum(R, N - 1, tight & (dig == limit));
    }
    return dp[N][tight] = total;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcases = 1;
    cin >> testcases;
    while (testcases--)
    {
        ll l, r;
        cin >> l >> r;
        if (l != 0)
            l--;
        string L = to_string(l);
        string R = to_string(r);
        memset(dp, -1, sizeof(dp));
        ll sumR = sum(R, R.length(), 1);
        memset(dp, -1, sizeof(dp));
        ll sumL = sum(L, L.length(), 1);
        cout << sumR - sumL << "\n";
    }

    return 0;
}