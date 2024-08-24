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
    int N, K;
    cin >> N >> K;
    vector<int> arr(N + 1, 0);
    for(int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        arr[a]++;
        arr[b + 1]--;
    }
    for(int i = 1; i <= N; i++)
    {
        arr[i] += arr[i - 1];
    }
    arr.pop_back();
    sort(arr.begin(), arr.end());
    cout << arr[(N - 1)/ 2] << endl;
}

int main()
{
    // freopen("hps.in", "r", stdin);
    // freopen("hps.out", "w", stdout);
    IOS;
    int test_case = 1;
    // cin >> test_case;
    int idx = 1;
    while (test_case--)
    {
        solve(idx);
        idx++;
    }
    return 0;
}