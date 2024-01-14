#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> apart(n);
    for (int i = 0; i < n; i++)
    {
        cin >> apart[i];
    }
    vector<int> size(m);
    for (int i = 0; i < m; i++)
    {
        cin >> size[i];
    }
    sort(apart.begin(), apart.end());
    sort(size.begin(), size.end());

    int ans = 0;
    int i = 0, j = 0;
    while (i < n)
    {
        while (j < m && size[j] < apart[i] - k)
            j++;
        if (j < m && size[j] <= apart[i] + k && size[j] >= apart[i] - k)
        {
            ans++;
            j++;
            i++;
        }
        else
            i++;
    }
    cout << ans << "\n";
    return 0;
}