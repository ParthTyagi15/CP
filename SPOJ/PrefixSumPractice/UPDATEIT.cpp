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

const int maxN = 50001;


void solve(int test_case)
{
    int N, U;
    cin >> N >> U;
    vector<ll> arr(N + 1, 0);
    for(int i = 0; i < U; i++)
    {
        int l, r, val;
        cin >> l >> r >> val;
        arr[l] += val;
        arr[r + 1] -= val;
    }
    for(int i = 1; i <= N; i++)
    {
        arr[i] += arr[i - 1];
    }
    arr.pop_back();
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int idx;
        cin >> idx;
        cout << arr[idx] << endl;
    }
}

int main()
{
    // freopen("hps.in", "r", stdin);
    // freopen("hps.out", "w", stdout);
    IOS;
    int test_case = 1;
    cin >> test_case;
    int idx = 1;
    while (test_case--)
    {
        solve(idx);
        idx++;
    }
    return 0;
}