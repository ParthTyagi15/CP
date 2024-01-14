#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve()
{
    int n;
    cin >> n;
    vector<int>v(n);
    ll sum = 0;
    for(auto &it : v){
        cin >> it;
        sum += it;
    }
    // dp[l][r] = sc1 - sc2
    // sc1 + sc2 = sum
    // sc1 = sum - sc2 => sc1 = sum - sc1 + dp[l][r] => sc1 = (sum + dp[l][r]) / 2;
    // dp[l][r] = sc1 - sum + sc1 = 2*sc1 - sum
    vector<vector<ll>>dp(n,vector<ll>(n,0));
    
    for(int l = n - 1; l >= 0; l--){
        for(int r = l; r < n; r++){
            if(l == r){
                dp[l][r] = v[l];
            }
            else{
                dp[l][r] = max(v[l] - dp[l + 1][r], v[r] - dp[l][r - 1]);
            }
        }
    }
    cout << (sum + dp[0][n - 1])/2 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
