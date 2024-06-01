#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

#define endl "\n"
#define pii pair<int, int>
#define INF 1e15

void solve(int test_case)
{
    ll N, M;
    cin >> N >> M;
    vector<vector<pii>> adj(N + 1);
    for (int i = 0; i < M; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    vector<ll> dist(N + 1, INF);
    vector<ll> par(N + 1, 0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    dist[1] = 0;
    q.push({dist[1], 1});
    while (!q.empty())
    {
        auto [d, node] = q.top();
        q.pop();
        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;
            if (dist[v] > dist[node] + wt)
            {
                dist[v] = dist[node] + wt;
                par[v] = node;
                q.push({dist[v], v});
            }
        }
    }
    if (dist[N] == INF)
    {
        cout << -1 << endl;
        return ;
    }
    vector<int> path;
    int cur = N;
    while (cur != 0)
    {
        path.push_back(cur);
        cur = par[cur];
    }
    reverse(path.begin(), path.end());
    for (auto it : path)
    {
        cout << it << " ";
    }
    cout << endl;
    return;
}

int main()
{
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    IOS;
    int test_case = 1;
    // cin >> test_case;
    int idx = 1;
    while (test_case--)
    {
        solve(idx);
        idx++;
    }
    return 0;
}