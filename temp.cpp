#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

#define endl "\n"
#define pii pair<int, int>

int N, M;
vector<vector<int>>adj;
vector<int>vis;
int timer = 1;
vector<vector<int>>res;
vector<int>low, tin;

void dfs(int node, int par = -1){
    vis[node] = 1;
    low[node] = tin[node] = timer++;
    for(auto x : adj[node]){
        if(x == par)continue;
        if(vis[x]){
            low[node] = min(low[node], tin[x]);
        }
        else{
            dfs(x, node);
            low[node] = min(low[node], low[x]);
            if(low[x] > tin[node]){
                res.push_back({min(node, x), max(node, x)});
            }
        }
    }
}

void solve(int test_case){
    res.clear();
    cin >> N >> M;
    tin.clear();
    low.clear();
    tin.resize(N + 1, -1);
    low.resize(N + 1, -1);
    vis.clear();
    vis.resize(N + 1, 0);
    adj.clear();
    adj.resize(N + 1);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= N; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    


    cout << "Caso #" << test_case << endl;
    if(res.size() == 0){
        cout << "Sin bloqueos\n";
        return;
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for(auto it : res){
        cout << it[0] << " " << it[1] << endl;
    }
}

int main()
{
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    IOS;
    int test_case = 1;
    cin >> test_case;
    int idx = 1;
    while (test_case--){
        solve(idx);
        idx++;
    }
    return 0;
}