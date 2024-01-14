#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int LOG = 21;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 1) read input
    int n, q;
    cin >> n >> q;
    ll a[n + 1];
    ll table[n + 1][LOG];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        table[i][0] = a[i];
    }

    // 2) Precomputations

    for (ll j = 1; j < LOG; j++)
    {
        for (ll i = 0; i + (1 << j) - 1 < n; i++)
        {
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }

    // 3) Answer queries

    for (ll i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        ll len = r - l + 1;
        ll k = 31 - __builtin_clz(len);
        cout << min(table[l][k], table[r - (1 << k) + 1][k]) << "\n";
    }

    return 0;
}