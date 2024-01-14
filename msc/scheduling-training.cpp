#include <bits/stdc++.h>

using namespace std;


int main() {
    int m;
    cin >> m;
    vector<vector<int>>course(2,vector<int>(m,0));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < m; j++){
            cin >> course[i][j];
        }
    }
    int p;
    cin >> p;
    vector<pair<int,int>>commit;
    for(int i = 0; i < p; i++){
        int a,b;
        cin >> a >> b;
        commit.push_back({a,b});
    }
    sort(commit.begin(),commit.end(),[](pair<int,int>&p1,pair<int,int>&p2){return p1.second < p2.second;});
    map<int,int>mp;
    for(auto it : commit){
        for(int i = it.first;i <= it.second; i++){
            mp[i] = 1;
        }
    }
    int left = -1;
    vector<int>freeTime;
    for(int i = 0; i < 24; i++){
        if(mp.find(i) != mp.end()){//occupied
            if(left == -1)continue;
            else{
                if(i - left != 0)
                freeTime.push_back(i - left);
                left = -1;
            }
        }
        else{
            // cout << "free " << i << endl;
            if(left == -1)
            left = i - 1;
        }
    }
    // for(auto it : freeTime){
    //     cout << it << " ";
    // }
    int i = 0,j = 0,k = 0;
    int cnt = 0;
    int curr = freeTime[k];
    while(i < m or j < m){
        if(course[0][i] + course[1][j] <= curr){
            curr -= course[0][i] + course[1][j];
            i++,j++;
        }
        else if(course[0][i] <= curr or course[1][j] <= curr){
            if(course[0][i] <= curr and course[1][j] <= curr){
                if(course[0][i] > course[1][j])
                {
                    curr -= course[0][i];
                    i++;
                }
                else{
                    curr -= course[0][j];
                    j++;
                }
            }
        }
        else{
            k++;
            cnt++;
            if(k == freeTime.size()){
                k = 0;
            }
            curr = freeTime[k];
        }
    }
    cout << cnt;
    cout << endl;
}