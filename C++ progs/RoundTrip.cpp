#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &par)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            par[it] = node;
            if (dfs(it, adj, vis, par))
            {
                return true;
            }
        }
        else if (par[node] == it)
        {
            continue;
        }
        else if (it != par[node])
        {

            while (node != it)
            {
                ans.push_back(node);
                node = par[node];
            }
            ans.push_back(it);
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    vector<int> par(n + 1, 0);
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            if (dfs(i, adj, vis, par))
            {
                cout << ans.size() + 1 << endl;
                cout << ans.back() << " ";
                for (auto it : ans)
                {
                    cout << it << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}

/*
10 8
3 4
7 8
5 4
6 7
9 8
5 6
3 2
1 2
*/