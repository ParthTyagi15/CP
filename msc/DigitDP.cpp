/*
Question: There are two integers n, m where 0 ≤ n ≤ m ≤ 1018. Find the number of integers between
n and m inclusive containing exactly k d digits. n, m, k, d are given in input.
Sample Input
(n, m, k, d) = (7, 111, 2, 1)
This translates to finding the number of integers in the range [7, 111] with exactly two 1
digits. There are three such integers: 11, 101, 110.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 100;
int dp[MAX_N][MAX_N][2];
int n, m, k, d;

void reset()
{
    memset(dp, -1, sizeof(dp));
}

int dfs(int c, int x = 0, int y = 0, bool z = 0)
{
    // dp state => dp[x][y][z];
    //  x->pos; y-># times k has been placed before pos; z->bool(basically constraint)
    if (dp[x][y][z] != -1)
        return dp[x][y][z];
    dp[x][y][z] = (y == k); // if we have already processed k d digits and the pos is out of digit sequence then =>
    if (x == to_string(c).length())
        return dp[x][y][z];

    int limit = 9;
    if (!z) // there is a tight constraint -> chances that number can exceed c
    {
        limit = to_string(c)[x] - '0'; // limit can be the xth digit of c
    }

    dp[x][y][z] = 0;
    for (int dig = 0; dig <= limit; dig++)
    {
        if (z) // no constraint is there
        {
            dp[x][y][z] += dfs(c, x + 1, y + (dig == d), 1);
        }
        else
        {
            dp[x][y][z] += dfs(c, x + 1, y + (dig == d), dig < limit);
        }
    }

    return dp[x][y][z];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k >> d;
    reset();
    int total = dfs(m);
    reset();
    cout << total - dfs(n - 1) << "\n";
    return 0;
}