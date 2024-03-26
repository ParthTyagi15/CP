#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (auto &x : c)
        cin >> x;
    if (c[0] == c[n - 1])
    {
        int cnt = 0;
        for (int x : c)
        {
            if (x == c[0])
                cnt++;
        }
        if (cnt >= k)
        {
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
        return;
    }
    else
    {
        int left = 0, left_cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (c[i] == c[0] and left_cnt < k)
            {
                left_cnt++;
                left = i;
            }
        }
        int right = n - 1, right_cnt = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (c[i] == c[n - 1] and right_cnt < k)
            {
                right_cnt++;
                right = i;
            }
        }
        if (left_cnt == k and right_cnt == k and left < right)
        {
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
