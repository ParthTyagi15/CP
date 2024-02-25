#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);

    for (auto &x : a)
        cin >> x;
    int ans = 0;
    ans = a[0];
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, a[i] - a[i - 1]);
    }
    ans = max(ans, 2*abs(a[n - 1] - x));
    cout << ans << endl;
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
