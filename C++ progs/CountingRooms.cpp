#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void dfs(vector<vector<char>>&grid,int i,int j){
    if(i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or grid[i][j] == '#'){
        return;
    }
    grid[i][j] = '#';
    for(int k = 0; k < 4; k++){
        dfs(grid,i + dx[k],j + dy[k]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<char>>grid(n,vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.'){
                dfs(grid,i,j);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}