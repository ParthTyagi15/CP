#include <bits/stdc++.h>
using namespace std;
using ll = long long;


const int maxN = (int)2e5 + 5;

vector<int>adj[maxN];




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int dia = 0;
    solve(dia);

    return 0;
}