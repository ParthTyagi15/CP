// #include <bits/stdc++.h>

// using namespace std;

// int main(){
//     vector<vector<int>>arr = {{1,2,3},{4,5,6,10},{7,8,9}};
//     // row-wise printing
//     for(int row = 0; row < arr.size(); row++){
//         for(int col = 0; col < arr[row].size(); col++){
//             cout << arr[row][col] << " ";
//         }
//     }
//     cout << "\n";
//     // col-wise
//     // row1 - 1 2 3 4
//     // row2 - 5 6 7 8 9 10
//     // row3 - 1 3 2
//     int mx = 0;
//     for(int i = 0; i < arr.size(); i++){
//         mx = max(mx, (int)arr[i].size());
//     }
//     int col = 0;
//     for(col = 0; col < mx; col++){
//         for(int row = 0; row < arr.size(); row++){
//             if(col < arr[row].size()){
//                 cout << arr[row][col] << " ";
//             }
//         }
//     }
//     cout << "\n";
//     // vector<int>login = {0900,940,950,1100,1500,1800};
//     // vector<int>logout = {910,1200,1120,1130,1900,2000};
//     // vector<pair<int,int>>vec;
//     // for(int i = 0; i < login.size(); i++){
//     //     vec.push_back({login[i],1});
//     //     vec.push_back({logout[i],-1});
//     // }
//     // sort(vec.begin(),vec.end());
//     // int mx = -1;
//     // int curr = 0;
//     // for(int i = 0; i < vec.size(); i++){
//     //     curr += vec[i].second;
//     //     mx = max(mx, curr);
//     // }
//     // cout << mx << "\n";

//     return 0;
// }

#include <vector>

int main(int r1, char **r2)
{
    int n;
    if (r1 > 1)
        n = r2[0][0];
    int *stuff = new int[n];
    std::vector<int> v(1000);
    delete stuff;
    return 0;
}
