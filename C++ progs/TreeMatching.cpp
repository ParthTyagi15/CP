#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxN = (int)2e5 + 5;

vector<int> adj[maxN];
vector<int> dist(maxN, 0);

void dfs(int node, int par)
{
    for (auto it : adj[node])
    {
        if (it != par)
        {
            dist[it] = dist[node] + 1;
            dfs(it, node);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    int farthest = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] > dist[farthest]){
            farthest = i;
        }
    }
    dist[farthest] = 0;
    dfs(farthest, 0);
    for(int i = 1; i <= n; i++){
        if(dist[i] > dist[farthest]){
            farthest = i;
        }
    }
    cout << dist[farthest] << endl;
    return 0;
}