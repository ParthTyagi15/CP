#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_X = (int)1e6;
const ll MOD = (int)1e9 + 7;
const int MAX_N = 100;
int n,x,c[MAX_N];
ll dp[MAX_X + 1];


int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> c[i];

    dp[0] = 1;
    for(int i = 1; i <= x; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i - c[j] >= 0)
            {
                dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
            }
        }
    }
    cout << dp[x] << "\n";
    return 0;
}