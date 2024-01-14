#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll cnt = 0;
    for (ll i = 1; i < n; i++)
    {
        if(v[i]<v[i-1])
        {
            cnt+=abs(v[i]-v[i-1]);
            v[i] = v[i-1];
            // cout<<v[i]<<" "<<cnt<<endl;
        }
        
    }
    cout<<cnt<<endl;
    return 0;
}