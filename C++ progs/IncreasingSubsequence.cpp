#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>arr(n,0);
    for(auto &it : arr){
        cin >> it;
    }
    vector<int>temp;
    temp.push_back(arr[0]);
    int len = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            int idx = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            temp[idx] = arr[i];
        }
    }
    cout << len << endl;
    return 0;
}