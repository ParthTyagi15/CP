#include<bits/stdc++.h>
using namespace std;

long long dp[1 << 21];

void solve(){
    int n;
    cin >> n;
    vector<vector<int>>v(20,vector<int>(20,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }
    memset(dp,0,sizeof(dp));
    // mask stores the information : number of set bits tells that 
    dp[0] = 1;
    for(int mask = 0; mask < (1 << n); mask++){
        int num = __builtin_popcount(mask);
        for(int i = 0; i < n; i++){
            if(v[num][i] == 1 and ((mask & (1 << i)) == 0))dp[mask | (1 << i)] += dp[mask];
        }
    }
    cout << dp[(1 << n) - 1] << "\n";
}

int main()
{
    int t = 1;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;       
    while(t--){
        solve();
    }
    return 0;
}