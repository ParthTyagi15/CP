#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)


vector<vector<int>> adj(2005);
int ans[2005];
int par[2005];

void bfs(int node)
{
    // cout << "Hi\n";
    int vis[2005] = {0};
    queue<pair<int, int>> q;
    q.push({node, 1});
    vis[node] = 1;
    par[node] = -1;
    while (!q.empty())
    {
        auto [u, dst] = q.front();
        q.pop();
        for (auto it : adj[u])
        {
            if (it == node)
            {
                while(node != -1){
                    ans[node] = min(ans[node], dst);
                    // cout << node << ": " << ans[node] << "\n";
                    node = par[node];
                }
                return;
            }
            if(vis[it] == 0){
                vis[it] = 1;
                par[it] = u;
                q.push({it, dst + 1});
            }
        }
    }
    ans[node] = -1;
    // cout << ans[node] << "\n";
    return;
}

int main()
{
    IOS;
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int temp;
            cin >> temp;
            if (temp)
                adj[i].push_back(j);
            
        }
    }
    for(int i = 0; i < 2005; i++){
        ans[i] = 200005;
    }
    for (int i = 1; i <= N; i++)
    {
        if(ans[i] == 200005){
            bfs(i);
            if(ans[i] == -1){
                cout << "NO WAY\n";
            }
            else{
                cout << ans[i] << "\n";
            }
        }
        else{
            cout << ans[i] << "\n";
        }
    }
    return 0;
}