#include <bits/stdc++.h>
using namespace std;
using ll = long long;



vector<ll> tree;

// RECURSIVE VERSION CAN HANDLE EVERYTHING

ll solve(ll node, ll node_low, ll node_high, ll query_low, ll query_high)
{
    if (query_low <= node_low and node_high <= query_high)
    {
        return tree[node];
    }
    if (node_high < query_low or query_high < node_low)
    {
        return INT_MAX;
    }

    ll mid = (node_high + node_low) / 2;

    return min(solve(2 * node, node_low, mid, query_low, query_high),solve(2 * node + 1, mid + 1, node_high, query_low, query_high));
}

// RECURSIVE VERSION OF UPDATE
void change(ll node, ll node_low, ll node_high, ll query_low, ll query_high, ll v)
{
    if (query_low <= node_low and node_high <= query_high)
    {
        tree[node] = v;
        return;
    }
    if (node_high < query_low or query_high < node_low)
    {
        return ;
    }

    ll mid = (node_high + node_low) / 2;
    change(2 * node, node_low, mid, query_low, query_high, v);
    change(2 * node + 1, mid + 1, node_high, query_low, query_high, v);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

/*
//ITERATIVE VERSION OF UPDATE
void update(ll i, ll new_val, ll n)
{
    tree[n + i] = new_val;
    for (int j = (n + i) / 2; j >= 1; j /= 2)
    {
        tree[j] = tree[2*j] + tree[2*j + 1];
    }
}
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 1) read input
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

    // Build the tree
    // Fill the leaf nodes with array values [8,15]
    for (ll i = 0; i < n; i++)
    {
        tree[n + i] = a[i];
    }
    // Go from there to root node(eg [7->1])

    for (ll i = n - 1; i >= 1; i--)
    {
        tree[i] = min(tree[2 * i],tree[2 * i + 1]);
    }

    // Answer query

    while (q--)
    {
        ll type;
        cin >> type;
        if (type == 2)
        {

            ll low, high;
            cin >> low >> high;
            low--, high--;

            cout << solve(1, 0, n - 1, low, high) << "\n";
        }
        else
        {
            ll k, v;
            cin >> k >> v;
            k--;
            // update(k,v,n);
            change(1, 0, n - 1, k, k, v);
        }
    }

    return 0;
}