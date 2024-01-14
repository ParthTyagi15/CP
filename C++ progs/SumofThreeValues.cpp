#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxN = 5000;
pair<int, int> a[maxN + 1];
int n, x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        a[i] = {b, i + 1};
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            if (a[i].first + a[j].first + a[k].first == x)
            {
                cout << a[i].second << " " << a[j].second << " " << a[k].second << endl;
                return 0;
            }
            else
            {
                if (a[i].first + a[j].first + a[k].first > x)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}