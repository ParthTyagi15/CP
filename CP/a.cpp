#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    string s(2 * n, '1');
    s[0] = s[1] = '0';
    // 0 represents single kayak person, 1 represents double kayak person
    int instability = 0, ans = INT_MAX;

    do
    {
        instability = 0;

        for (int i = 0; i < 2 * n; i++)
        {
            if (s[i] == '1')
            {
                int j = i + 1;
                for (j = i + 1; j < 2 * n and s[j] == '0'; j++)
                {
                    continue;
                }
                instability += v[j] - v[i];
                i = j;
            }
        }
        ans = min(ans, instability);
    } while (next_permutation(s.begin(), s.end()));

    cout << ans << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}