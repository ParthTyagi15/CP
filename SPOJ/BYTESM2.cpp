#include<bits/stdc++.h>
using namespace std;

int dp[101][101];

int f(vector<vector<int>>&tiles,int i, int j){
    if(i < 0 or j < 0 or i >= tiles.size() or j >= tiles[i].size())return 0;
    if(dp[i][j] != -1)return dp[i][j];
    return dp[i][j] = tiles[i][j] + max({f(tiles,i + 1,j - 1),f(tiles,i + 1,j),f(tiles,i + 1,j + 1)});
}

void solve(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>>tiles(n,vector<int>(m));
    memset(dp,-1,sizeof(dp));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> tiles[i][j];
        }
    }

    int ans = 0;

    for(int i = 0; i < m; i++){
        ans = max(ans, f(tiles,0,i));
    }
    cout << ans << "\n";
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