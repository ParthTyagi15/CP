#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxN = 200001;

vector<int>parent(maxN, 0), answer(maxN, 0);

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>>queries;
    for(int i = 0; i < q; i++){
        int l,r,c;
        cin >> l >> r >> c;
        queries.push_back({l - 1, r - 1 , c});
    }
    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }
    
    for(int i = q - 1; i >= 0; i--){
        int l = queries[i][0], r = queries[i][1], c = queries[i][2];
        int node = find_set(l);
        while(node <= r) {
            answer[node] = c;
            parent[node] = node + 1;
            node = find_set(node);
        }
        // for(int i = 1; i <= n; i++){
        //     cout << answer[i] << " ";
        // }
        // cout << endl;
        // for(int i = 1; i <= n; i++){
        //     cout << parent[i] << " ";
        // }
        // cout << endl;
    }
    for(int i = 0; i < n; i++){
        cout << answer[i] << "\n";
    }
    return 0;
}