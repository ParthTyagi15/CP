#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,t;
vector<ll>arr;

bool check(ll res){
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += res/arr[i];
        if(cnt >= t)return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> t;
    arr.resize(n);
    for(auto &it : arr)cin >> it;
    ll lo = 0, hi = 1e18;
    ll ans = 0;
    while(lo <= hi){
        ll mid = lo + (hi - lo)/2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
