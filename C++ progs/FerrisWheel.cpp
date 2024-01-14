#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    int l = 0;
    for (int i = n - 1; i >= l; i--)
    {
        if (v[i] + v[l] <= x)
        {
            l++;
        }
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}