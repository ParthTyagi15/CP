#include<bits/stdc++.h>
using namespace std;


int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>>adj(n + 1);
    vector<int>indegree(n + 1, 0);

    vector<int>ans;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    // priority_queue<int,vector<int>,greater<int>>q;
    queue<int>q;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    if(ans.size() != n){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(auto it : ans){
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}