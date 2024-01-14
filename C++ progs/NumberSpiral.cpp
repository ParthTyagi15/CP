#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll y, x;
        cin >> x >> y;
        ll l = max(y, x) - 1;
        ll ans;
        if (l & 1)
        {
            if (x < y)
                ans = l * l + x;
            else
                ans = l * l + 2 * l - y + 2;
        }
        else
        {
            if (x < y)
                ans = l * l + 2 * l - x + 2;
            else
                ans = l * l + y;
        }
        cout << ans << "\n";
    }

    return 0;
}