#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<pair<ll, ll>> tree;

pair<ll, ll> combine(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first > b.first)
    {
        return b;
    }
    else if (a.first < b.first)
    {
        return a;
    }
    return {a.first, a.second + b.second};
}

pair<ll, ll> solve(ll node, ll node_low, ll node_high, ll query_low, ll query_high)
{
    if (query_low <= node_low and node_high <= query_high)
    {
        return tree[node];
    }
    if (node_high < query_low or query_high < node_low)
    {
        return {1e9, 0};
    }

    ll mid = (node_high + node_low) / 2;
    return combine(solve(2 * node, node_low, mid, query_low, query_high), solve(2 * node + 1, mid + 1, node_high, query_low, query_high));
}

void update(ll node, ll node_low, ll node_high, ll query_low, ll query_high, ll v)
{
    if (query_low <= node_low and node_high <= query_high)
    {
        tree[node] = {v, 1};
        return;
    }
    if (node_high < query_low or query_high < node_low)
    {
        return;
    }

    ll mid = (node_high + node_low) / 2;
    update(2 * node, node_low, mid, query_low, query_high,v);
    update(2 * node + 1, mid + 1, node_high, query_low, query_high,v);
    tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto &it : a)
        cin >> it;

    while (__builtin_popcount(n) != 1)
    {
        a.push_back(INT_MAX);
        n++;
    }
    tree.resize(2 * n);

    for (ll i = 0; i < n; i++)
        tree[n + i] = {a[i], 1};

    for (ll i = n - 1; i >= 1; i--)
    {
        tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
    }

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll k, v;
            cin >> k >> v;
            update(1, 0, n - 1, k, k, v);
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            b--;
            pair<ll, ll> ans = solve(1, 0, n - 1, a, b);
            cout << ans.first << " " << ans.second << endl;
        }
    }
    return 0;
}