#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll MAX_N = (ll)1e6 + 5;
const ll MOD = (ll)1e9 + 7;
 

int main()
{
    vector<vector<ll>> dp(MAX_N, vector<ll>(2, 0)); // dp[i][j] = number of ways to make tower of height i with (j == 0 meaning two blocks of width 1 and j == 1 meaning one block of width 2) j  as last block.

    dp[1][0] = 1;
    dp[1][1] = 1;

    for(ll i = 2; i < MAX_N; i++){
        // at position i we can place 2 block of width 1 in these cases:
        // 1. i - 1th position had a block of width 1(we break the last height and start new height) or width 2 (no choice but to break the last height and start new height)
        // 2. i - 1th position had 2 blocks of width 1 and we want to extend them.
        // 3. i - 1th postion had 1 block of width 1 which we want to extend. (there are 2 ways)
        dp[i][0] = ((dp[i - 1][0] + dp[i - 1][1]) + (dp[i - 1][0]) + (2 * dp[i - 1][0])) % MOD;


        // at position i we can place 1 block of width 2 in these cases:
        // 1. i - 1th position had 2 block of width 1(we break the last height and start new height)
        // 2. i - 1th position had 1 block of width 2 which we can extend.
        // 3. i - 1th position had 1 block of width 1 which we don't extend.
        dp[i][1] = ((dp[i - 1][0]) + (dp[i - 1][1]) + (dp[i - 1][1])) % MOD;
    }

    ll tt;
    cin >> tt;
    while(tt--){
        ll n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << endl;
    }
    return 0;
}