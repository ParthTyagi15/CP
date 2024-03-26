#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxN = (int)2e5 + 5;

vector<int> adj[maxN];
vector<int> picked(maxN, 0);
int cnt = 0;

void dfs(int node, int par)
{
    for (auto it : adj[node])
    {
        if (it != par)
        {
            dfs(it, node);
        }
    }
    if(par != 0 and !picked[node] and !picked[par]){
        cnt += 1;
        picked[node] = 1;
        picked[par] = 1;
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
    cout << cnt << "\n";
    return 0;
}