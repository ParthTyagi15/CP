#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,x;
vector<ll>arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    arr.resize(n);
    for(auto &it : arr){
        cin >> it;
    }
    // Space complexity O(N): Uses Map
    // unordered_map<ll,ll>mp;
    // mp[0] = 1;
    // ll sum = 0;
    // ll cnt = 0;
    // for(int i = 0; i < n; i++){
    //     sum += arr[i];
    //     if(mp.find(sum - x) != mp.end()){
    //         cnt += mp[sum - x];
    //     }
    //     mp[sum]++;
    // }
    // cout << cnt << "\n";

    // Method-2 Space complexity O(1): Uses two pointers
    ll sum = 0, res = 0, left = 0;
    for(int right = 0; right < n; right++){
        sum += arr[right];
        while(sum > x){
            sum -= arr[left];
            left += 1;
        }
        if(sum == x){
            res += 1;
        }
    }
    cout << res << endl;
    return 0;
}
