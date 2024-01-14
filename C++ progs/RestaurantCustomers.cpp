#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first == p2.second ? p1.second < p2.second : p1.first < p2.first;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, -1});
    }
    sort(v.begin(), v.end(), comp);
    int ans = 0, cur = 0;
    for (int i = 0; i < v.size(); i++)
    {
        cur += v[i].second;
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
