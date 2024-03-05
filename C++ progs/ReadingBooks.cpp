#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<ll>arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    arr.resize(n);
    ll mx = LONG_LONG_MIN;
    ll sum = 0;
    for(auto &it : arr){
        cin >> it;
        sum += it;
        mx = max(mx, it);
    }
    cout << max(sum, 2 * mx) << "\n";
    return 0;
}
