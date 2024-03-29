#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxN = (int)2e5 + 5;

vector<int> adj[maxN];

ll n;
ll ans[maxN];
ll no_of_node_in_subtrees[maxN];

void dfs(int node, int par, int depth = 0)
{
    ans[1] += depth;
    no_of_node_in_subtrees[node] = 1;
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        dfs(it, node, depth + 1);
        no_of_node_in_subtrees[node] += no_of_node_in_subtrees[it];
    }
}

void dfs2(int node, int par)
{
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        ans[it] = ans[node] + n - 2 * no_of_node_in_subtrees[it];
        dfs2(it, node);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(ans, 0, sizeof(ans));
    memset(no_of_node_in_subtrees, 0, sizeof(no_of_node_in_subtrees));
    dfs(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}