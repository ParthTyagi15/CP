/*
    Essentially we need to find the minimum spanning tree of the graph.
*/
#include<bits/stdc++.h>
using namespace std;
 
#define i64 int64_t
 
class DSU {
public:
    vector<int> par, size;
    DSU(int n) {
        par.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if(par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }

    void join(int x, int y) {
        x = find(x);
        y = find(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            par[y] = x;
            size[x] += size[y];
            return ;
        }
        return;
    }
};

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vector<int>>edges;
    for(int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    DSU ds(N);
    sort(edges.begin(), edges.end());
    i64 res = 0;

    for(auto &edge : edges) {
        int w = edge[0], u = edge[1], v = edge[2];
        if(ds.find(u) != ds.find(v)) {
            ds.join(u, v);
            res += w;
        }
    }
    bool flag = false;
    for(int i = 1; i <= N; i++) {
        if(!flag and ds.find(i) == i) {
            flag = true;
        }
        else if(flag and ds.find(i) == i) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    cout << res << '\n';
    return 0;
}