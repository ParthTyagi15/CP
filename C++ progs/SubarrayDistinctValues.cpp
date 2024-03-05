#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;
vector<ll>arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    arr.resize(n);
    for(auto &it : arr){
        cin >> it;
    }
    unordered_map<ll,ll>mp;
    int left = 0, right = 0;
    ll ans = 0;
    for(right = 0; right < n; right++){
        mp[arr[right]]++;
        while(mp.size() > k){
            mp[arr[left]]--;
            if(mp[arr[left]] == 0)mp.erase(arr[left]);
            left++;
        }
        ans += (right - left + 1);
    }
    cout << ans << "\n";
    return 0;
}
