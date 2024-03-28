#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxN = (int)2e5 + 5;

vector<int> adj[maxN];

int firstMax[maxN], secondMax[maxN];
int c[maxN]; // stores child for path of maxLength
int ans[maxN];

void dfs(int node, int par)
{
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        dfs(it, node);

        if (firstMax[it] + 1 > firstMax[node])
        {
            secondMax[node] = firstMax[node];
            firstMax[node] = firstMax[it] + 1;
        }
        else if (firstMax[it] + 1 > secondMax[node])
            secondMax[node] = firstMax[it] + 1;
    }
}

void dfs2(int node, int par, int dist_excluding_subtree = 0)
{
    ans[node] = max(dist_excluding_subtree, firstMax[node]);
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        if (firstMax[it] + 1 == firstMax[node])
        {
            dfs2(it, node, max(dist_excluding_subtree,secondMax[node]) + 1);
        }
        else
        {
            dfs2(it, node, ans[node] + 1);
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
    memset(ans, 0, sizeof(ans));
    memset(firstMax, 0, sizeof(firstMax));
    memset(secondMax, 0, sizeof(secondMax));
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
    {
        cout << firstMax[i] << " ";
    }
    cout << '\n';
    for (int i = 1; i <= n; i++){
        cout << secondMax[i] << " ";
    }
    cout << '\n';
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}