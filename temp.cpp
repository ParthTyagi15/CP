#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const int maxN = (int)(2e5 + 5);

void solve()
{
    ll n, c, d;
    cin >> n >> c >> d;
    unordered_map<ll, ll> mp;
    ll a11 = 1e9;
    for (int i = 0; i < n * n; i++)
    {
        ll x;
        cin >> x;
        a11 = min(a11, x);
        mp[x] += 1;
    }
    ll first = a11;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            first += c;
        }
        ll x = first;
        for (int j = 0; j < n; j++)
        {
            if (j > 0)
            {
                x += d;
            }
            // cout << x << " ";
            if (mp.find(x) != mp.end())
            {
                mp[x] -= 1;
                if (mp[x] == 0)
                    mp.erase(x);
            }
            else{
                cout << "No\n";
                return;
            }
        }
        // cout << endl;
    }
    if (mp.empty())
    {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
    return;
}

int main()
{
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    IOS;
    int test_case = 1;
    cin >> test_case;

    while (test_case--)
        solve();

    /*
     */
    return 0;
}
