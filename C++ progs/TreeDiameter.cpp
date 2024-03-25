#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxN = (int)2e5 + 5;

vector<int> adj[maxN];

int height(int root, int& dia){
    if(adj[root].size() == 0)
        return 0;
    int h = 0;
    
    for(auto it : adj[root]){
        h = max(h, 1 + height(it));
    }
    dia = max(dia, h);
    return h;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> indeg(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    int root = 0;
    for (int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            root = i;
            break;
        }
    }
    cout << height(root) << endl;

    return 0;
}