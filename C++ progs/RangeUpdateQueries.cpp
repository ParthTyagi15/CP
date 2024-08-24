#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

#define endl "\n"
#define pii pair<int, int>
#define INF 1e15

const int maxN = 2e5 + 5;


// template<class T> class BIT{
// public:
//     int N;
//     vector<T> bit;

//     BIT() : N(0) {}

//     BIT(int n) : N(n), bit(n + 1, 0){}
    
//     void add(int idx, T val){
//         for (; idx <= N; idx += (idx & -idx)) {
//             bit[idx] += val;
//         }
//     }
    
//     T sum(int idx){
//         T res = 0;
//         for(; idx > 0; idx -= (idx & -idx)){
//             res += bit[idx];
//         }
//         return res;
//     }

//     T sum(int l, int r){
//         return sum(r) - sum(l - 1);
//     }

// };

class SegmentTree{
public:
    int N;
    vector<ll>tree;

    SegmentTree() : N(0) {}

    SegmentTree(int n) : N(n), tree(4 * n, 0) {}

    void build(vector<int>&arr){
        while(__builtin_popcount(N) != 1){
            arr.push_back(0);
            N++;
        }

         // Build the tree
        // Fill the leaf nodes with array values [8,15]
        for (ll i = 0; i < N; i++)
        {
            tree[N + i] = a[i];
        }
        // Go from there to root node(eg [7->1])

        for (ll i = N - 1; i >= 1; i--)
        {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }

    void update(int idx, int l, int r, int pos, ll val){
        if(l == r){
            tree[idx] += val;
            return;
        }
        if(l > pos or r < pos){
            return;
        }
        int mid = (l + r) / 2;
        update(2 * idx, l, mid, pos, val);
        update(2 * idx + 1, mid + 1, r, pos, val);
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

    ll query(int idx, int l, int r, int ql, int qr){
        if(ql <= l and r <= qr){
            return tree[idx];
        }
        if(r < ql or l > qr){
            return 0;
        }
        int mid = (l + r) / 2;
        return query(2 * idx, l, mid, ql, qr) + query(2 * idx + 1, mid + 1, r, ql, qr);
    }
};


int main()
{
    // freopen("hps.in", "r", stdin);
    // freopen("hps.out", "w", stdout);
    IOS;
    int N, Q;
    cin >> N >> Q;
    // vector<ll>arr(N);
    // for(auto &x : arr){
    //     cin >> x;
    // }
    // SegmentTree st(N);

    // st.build(arr);

    // while(Q--){
    //     int type;
    //     cin >> type;
    //     if(type == 1){
    //         int l, r, x;
    //         cin >> l >> r >> x;
    //         // update(idx, low, high, pos, val)
    //         st.update(1, 1, N, l, x);
    //         st.update(1, 1, N, r + 1, -x);
    //     }
    //     else{
    //         int k;
    //         cin >> k;
    //         cout << st.query(1, 1, N, 1, k) << endl;
    //     }
    // }

    // BIT<long long> bit(N);

    // for(int i = 1; i <= N; i++){
    //     int x;
    //     cin >> x;
    //     bit.add(i, x);
    //     bit.add(i + 1, -x);
    // }

    // while(Q--){
    //     int type;
    //     cin >> type;
    //     // Range Update
    //     if(type == 1){
    //         int l, r, x;
    //         cin >> l >> r >> x;
    //         bit.add(l, x);
    //         bit.add(r + 1, -x);
    //     }
    //     // Point query
    //     else{
    //         int k;
    //         cin >> k;
    //         cout << bit.sum(k) << endl;
    //     }
    // }
    
    return 0;
}
