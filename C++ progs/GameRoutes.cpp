#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 1e5 + 1;
const ll mod = (int)1e9 + 7;
ll n, m;
vector<vector<ll>>adj(maxN);
vector<ll>indeg(maxN, 0);

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indeg[y] += 1;
    }
    queue<ll>q;
    vector<ll>dp(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    dp[1] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            dp[it] = (dp[it] + dp[node]) % mod;
            indeg[it] -= 1;
            if(indeg[it] == 0){
                q.push(it);
            }
        }
    }
    cout << dp[n] << "\n";
    return 0;
}