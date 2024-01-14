#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    vector<bool>vis(n + 1,false);
    vector<int>dist(n + 1,0);
    vector<int>par(n + 1);
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int it : adj[node])
        {
            if(vis[it] == false){
                dist[it] = dist[node] + 1;
                par[it] = node;
                vis[it] = true;
                q.push(it);
            }
        }
    }
    if(!vis[n]){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int node = n;
    int dis = dist[n];
    vector<int>ans(dis + 1);
    for(int i = dis; i >= 0; i--){
        ans[i] = node;
        node = par[node];
    }
    cout << dis + 1 << endl;
    for(auto it : ans){
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}