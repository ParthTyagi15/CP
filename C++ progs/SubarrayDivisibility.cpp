#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,x;
vector<ll>arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    arr.resize(n);
    for(auto &it : arr){
        cin >> it;
    }
    unordered_map<ll,ll>mp;
    mp[0] = 1;
    ll sum = 0;
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];

        ll k = ((sum % n) + n) % n;
        if(mp.find(k) != mp.end()){
            cnt += mp[k];
        }
        mp[k]++;
    }
    cout << cnt << "\n";
    return 0;
}
