#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

const int maxN = 2e5 + 5;
const int LOG = 20;

vector<int> adj[maxN];
vector<int> depth(maxN);
vector<vector<int>> up(maxN, vector<int>(LOG, 0));
vector<int>subordinates(maxN, 0);

void dfs(int node)
{
    for (int j = 1; j < LOG; j++)
        up[node][j] = up[up[node][j - 1]][j - 1];
    for (auto it : adj[node])
    {
        if (it == up[node][0])
            continue;
        up[it][0] = node;
        depth[it] = depth[node] + 1;
        dfs(it);
    }
}

int get_lca(int a, int b)
{
    if (depth[a] < depth[b])
    {
        swap(a, b);
    }
    int k = depth[a] - depth[b];
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (k & (1 << i))
        {
            a = up[a][i];
        }
    }
    if (a == b)
        return b;

    for (int i = LOG - 1; i >= 0; i--)
    {
        if (up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

void dfs2(int node = 1){
    for(auto it : adj[node]){
        if(it != up[node][0]){
            dfs2(it);
            subordinates[node] += subordinates[it];
        }
    }
}

int main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    depth[1] = 0;
    dfs(1);

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        int lca = get_lca(a, b);
        subordinates[a]++;
        subordinates[b]++;
        subordinates[lca]--;
        if(lca != 1)
            subordinates[up[lca][0]]--;
        // for(int i = 1; i <= n; i++){
        //     cout << subordinates[i] << " ";
        // }
        // cout << endl;
    }

    dfs2();
    // cout << "Ans: ";
    for(int i = 1; i <= n; i++){
        cout << subordinates[i] << " ";
    }
    cout << endl;
    return 0;
}