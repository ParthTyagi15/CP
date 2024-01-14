#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<pair<ll,ll>>v(n);
    for(ll i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end(),[](pair<ll,ll>a,pair<ll,ll>b){return a.first < b.first;});
    ll f = 0;
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        f += v[i].first;
        ans += (v[i].second - f);
    }
    cout << ans << "\n";
    return 0;
}