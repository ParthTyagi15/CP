#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

void bfs(vector<vector<int>>mat,int fx,int fy,int ix,int iy,int jx,int jy){
    // int time = 1;
    queue<pair<int,pair<int,int>>>q;
    q.push({1,{fx,fy}});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int t = it.first;
        int x = it.second.first;
        int y = it.second.second;
        mat[x][y] = t;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 and nx < mat.size() and ny >= 0 and ny < mat[0].size() and mat[nx][ny] == 0){
                q.push({t + 1,{nx,ny}});
            }
        }
    }
    
    queue<pair<int,pair<int,int>>>q2;
    q2.push({1,{ix,iy}});
    while(!q2.empty()){
        auto it = q2.front();
        q2.pop();
        int t = it.first;
        int x = it.second.first;
        int y = it.second.second;
        if(t >= mat[x][y]){
            cout << "NO\n";
            return;
        }
        if(x == jx and y == jy){
            cout << "YES\n";
            return;
        }
        mat[x][y] = -1;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 and nx < mat.size() and ny >= 0 and ny < mat[0].size() and mat[nx][ny] != -1){
                q2.push({t + 1,{nx,ny}});
            }
        }
    }
    // for(auto it : mat){
    //     for(auto i : it){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    return;
}

int main() {
    int m,n;
    cin >> m >> n;
    vector<vector<int>>mat(n,vector<int>(m,0));
    int t;
    cin >> t;
    while(t--){
        // memset(mat,0,sizeof(mat));
        int fx,fy,ix,iy,jx,jy;
        cin >> fx >> fy >> ix >> iy >> jx >> jy;
        bfs(mat,fx,fy,ix,iy,jx,jy);
    }
}