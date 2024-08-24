#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define i64 int64_t


int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    vector<vector<i64>> edges;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }
    vector<i64>dist(N + 1);
    vector<int>par(N + 1, -1);
    int x;
    for(int i = 1; i <= N; i++){
        x = -1;
        for(auto edge : edges){
            if(dist[edge[0]] + edge[2] < dist[edge[1]]){
                dist[edge[1]] = dist[edge[0]] + edge[2];
                par[edge[1]] = edge[0];
                x = edge[1];
            }
        }
    
    }
    if(x == -1){
        cout << "NO\n";
    }else{
        for(int i = 0; i < N; i++){
            x = par[x];
        }
        vector<int>cycle;
        for(int v = x;; v = par[v]){
            cycle.push_back(v);
            if(v == x && cycle.size() > 1){
                break;
            }
        }
        reverse(cycle.begin(), cycle.end());
        cout << "YES\n";
        for(auto it : cycle){
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}