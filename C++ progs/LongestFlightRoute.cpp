#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 1e5 + 1;
ll n, m;
vector<vector<ll>>adj(maxN);
vector<ll>dist(maxN, -1);
vector<ll>parent(maxN, -1);
vector<ll>vis(maxN, 0);
vector<ll>indeg(maxN, 0);

void dfs(int node, int par = 0){
    vis[node] = 1;
    // cout << node << " ";
    for(auto it : adj[node]){
        if(it == par) continue;
        if(!vis[it])
            dfs(it, node);
    }
}

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
    dfs(1);
    // for(int i = 1; i <= n; i++){
    //     cout << indeg[i] << " ";
    // }
    // cout << endl;
    queue<ll>q;
    if(!vis[n]){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    dist[1] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if(dist[node] != -1 and dist[it] < dist[node] + 1){
                dist[it] = dist[node] + 1;
                parent[it] = node;
            }
            indeg[it] -= 1;
            if(indeg[it] == 0){
                q.push(it);
            }
        }
    }
    ll k = dist[n] - dist[1];
    cout << k + 1 << "\n";
    vector<ll>ans(k + 1);
    ll node = n;
    for(int i = k; i >= 0; i--){
        ans[i] = node;
        node = parent[node];
    }
    for(auto it : ans){
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}