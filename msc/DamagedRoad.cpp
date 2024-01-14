#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
typedef long long int ll;

int main()
{
    ll n, m;
    cin >> n >> m;
    ll a[n];
    ll b[m];
    vector<pair<ll, ll>> vec;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
        vec.push_back({a[i], 1});
    }
    for (int i = 0; i < m - 1; i++)
    {
        cin >> b[i];
        vec.push_back({b[i], 2});
    }
    int rdone = 0;
    int cdone = 0;
    int rownum = m;
    int colnum = n;
    ll ans = 0;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].second == 1)
        {
            ans = ans + vec[i].first * (m - cdone);
            rdone++;
        }
        else
        {
            ans = ans + vec[i].first * (n - rdone);
            cdone++;
        }
        ans = ans % M;
    }
    cout << ans << endl;
}