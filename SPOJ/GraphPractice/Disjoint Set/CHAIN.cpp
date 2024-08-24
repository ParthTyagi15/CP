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

const int maxN = 50001;


class DSU {
public:
    vector<ll>parent, depth;
    int size;
    DSU(int n) {
        size = n;
        parent.resize(n + 1);
        depth.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            depth[i] = 0;
        }
    }

    int findPar(int node) {
        if(node == parent[node])return node;
        int par = parent[node];
        parent[node] = findPar(parent[node]);
        depth[node] = (depth[node] + depth[par]) % 3;
        return parent[node];
    }

    bool UnionSet(int x, int y, int d) {
        if(x >= size or y >= size) {
            return false;
        }
        int par_x = findPar(x);
        int par_y = findPar(y);

        if(par_x == par_y){
            return ((depth[x] - depth[y]) % 3 + 3) % 3 == d;
        }
        else{
            parent[par_y] = par_x;
            depth[par_y] = ((depth[x] - depth[y] - d) % 3 + 3) % 3;
            return true;
        }
    }

};

void solve(int test_case)
{
    ll n, k;
    cin >> n >> k;
    
    ll cnt = 0;
    DSU ds = DSU(n);
    for(ll i = 0; i < k; i++){
        ll type, x, y;
        cin >> type >> x >> y;
        type--;
        x--;
        y--;
        if(ds.UnionSet(x, y, type) == false){
            cnt++;
        }
    }
    cout << cnt << "\n";
}

int main()
{
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    IOS;
    int test_case = 1;
    cin >> test_case;
    int idx = 1;
    while (test_case--)
    {
        solve(idx);
        idx++;
    }
    return 0;
}