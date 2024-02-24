#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    ll cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
            cnt++;
    }
    if(k == 1)
    {
        if(cnt == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
        return;
    }
    cout << "Yes\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
