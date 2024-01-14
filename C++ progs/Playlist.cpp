#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int, int> mp;
    int n;
    cin >> n;
    int j = 1, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        if (mp[k])
        {
            ans = max(ans, i - j);
            j = max(j, mp[k] + 1);
            mp[k] = i;
        }
        else
        {
            ans = max(ans, i - j + 1);
            mp[k] = i;
        }
    }
    ans = max(ans, n - j + 1);
    cout << ans << endl;
    return 0;
}