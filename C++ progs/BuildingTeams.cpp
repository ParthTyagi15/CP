#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<int>adj[n + 1];
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n + 1,-1);

    for(int i = 1; i <= n; i++){
        if(vis[i] == -1){
            vis[i] = 1;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int t = q.front();
                q.pop();
                for(auto it : adj[t]){
                    if(vis[it] == -1){
                        vis[it] = 1 - vis[t];
                        q.push(it);
                    }
                    else{
                        if(vis[it] == vis[t]){
                            cout << "IMPOSSIBLE\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            cout << 2 << " ";
        }
        else
        cout << vis[i] << " ";
    }
    cout << endl;
    return 0;
}