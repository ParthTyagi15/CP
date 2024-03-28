#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxN = (int)2e5 + 5;

vector<int> adj[maxN];
vector<int> dist(maxN, 0);

/* void dfs(int node, int par)
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
*/
int f[maxN], g[maxN], diameter;

// f[x] = Longest path from node x to one subtree of x
// g[x] = Longest path starting from one subtree of x and ending in another subtree

void dfs(int node, int par)
{
    vector<int> fValues; // stores value of f for all children of 'node'

    for (auto it : adj[node])
    {
        if (par == it)
            continue;
        dfs(it, node);
        fValues.push_back(f[it]);
    }
    sort(fValues.begin(), fValues.end());
    f[node] = 0;
    if (fValues.size() >= 1)
        f[node] = 1 + fValues.back();
    if (fValues.size() >= 2)
        g[node] = 2 + fValues.back() + fValues[fValues.size() - 2];
    diameter = max(diameter, max(f[node], g[node]));
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
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    diameter = 0;
    dfs(1, 0);
    cout << diameter << "\n";
    for(int i = 1; i <= n; i++){
        cout << f[i] << " ";
    }
    cout << '\n';
    /* dfs(1, 0);
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
    */

    return 0;
}
