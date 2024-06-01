#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int N, R, M;
    cin >> N >> R >> M;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < R; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int city, strength;
        cin >> city >> strength;
        if(vis[city]){
            cout << city << ": No\n";
            return;
        }
        queue<int> q;
        q.push(city);
        vis[city] = true;
        int level = 0;
        while (!q.empty())
        {
            int sz = q.size();
            for (int j = 0; j < sz; j++)
            {
                int u = q.front();
                q.pop();
                for (auto v : adj[u])
                {
                    if (!vis[v])
                    {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
            level++;
            if (level > strength)
            {
                break;
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {

        if (!vis[i])
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}