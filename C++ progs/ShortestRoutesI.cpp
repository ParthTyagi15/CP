#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

const int maxN = (int)1e5;
vector<pair<ll,ll>>adj[maxN + 1];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        ll u,v,wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
    }
    ll dist[maxN + 1];
    memset(dist,10000,sizeof(dist));
    dist[1] = 0;
    // for(int i = 1; i <= n; i++){
    //     cout << dist[i] << " ";
    // }
    // cout << endl;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,1}); // dist,node

    while(!pq.empty()){
        auto ed = pq.top();
        pq.pop();
        ll u = ed.second;
        ll d = ed.first;
        if(dist[u] < d)continue;
        for(auto it : adj[u]){
            ll v = it.first;
            ll wt = it.second;
            if(dist[v] > d + wt){
                dist[v] = d + wt;
                pq.push({d + wt,v});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}
