#include <bits/stdc++.h>
using namespace std;

const int maxN = 200005;
vector<int>adj[maxN];
int sub[maxN];

void dfs(int node, int depth, int par){
    sub[node] = 1;
    for(auto it : adj[node]){
        if(it != par){
            dfs(it, depth + 1, node);
            sub[node] += sub[it];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        int in;
        cin >> in;
        adj[i].push_back(in);
        adj[in].push_back(i);
    }

    dfs(1,0,0);
    for(int i = 1; i <= n; i++){
        cout << sub[i] - 1 << " ";
    }
    cout << "\n";
    return 0;
}