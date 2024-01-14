#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    long long ans = LONG_MAX;
    for (int i = 0; i < (1 << n); i++)
    {
        long long a = 0, b = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                a += v[j];
            }
            else
            {
                b += v[j];
            }
        }
        ans = min(ans, abs(a - b));
    }
    cout << ans << "\n";
    return 0;
}