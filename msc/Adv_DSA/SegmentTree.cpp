#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// THIS IS NORMAL SEGMENT TREE THAT CAN BE USED FOR RANGE QUERIES AND POINT UPDATES
class SegTree{
public:
    int N;
    vector<int64_t>tree;
    SegTree(int n) : N(n) {}
    void build(vector<int>&arr) {
        while (__builtin_popcount(N) != 1)
        {
            arr.push_back(0);
            N++;
        }
        tree.resize(2 * N, 0);
        for(int i = 0; i < N; i++){
            tree[N + i] = arr[i];
        }
        for(int i = N - 1; i >= 1; i--){
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }

    void update(int node, int low, int high, int left, int right, int val) {
        if(left <= low and high <= right) {
            tree[node] = val;
            return;
        }
        if(high < left or low > right)return;
        int mid = (low + high) / 2;
        update(2 * node, low, mid, left, right, val);
        update(2 * node + 1, mid + 1, high, left, right, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int low, int high, int left, int right) {
        if(left <= low and high <= right) {
            return tree[node];
        }
        if(high < left or low > right)return 0;

        int mid = (low + high) / 2;

        return query(2 * node, low, mid, left, right) + query(2 * node + 1, mid + 1, high, left, right);
    }
};
//SEGMENT TREE FOR RANGE SUM QUERIES -> CAN MODIFY IT ACCORDINGLY

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
        return 0;
    }

    ll mid = (node_high + node_low) / 2;

    return solve(2 * node, node_low, mid, query_low, query_high) + solve(2 * node + 1, mid + 1, node_high, query_low, query_high);
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
    tree[node] = tree[2 * node] + tree[2 * node + 1];
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
        a.push_back(0);
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
        tree[i] = tree[2 * i] + tree[2 * i + 1];
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