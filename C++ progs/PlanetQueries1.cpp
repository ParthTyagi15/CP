#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
const int MOD = 1000000007;
using ll = long long;

const int maxN = 2e5 + 5;

int up[maxN][32];

int main()
{
    IOS;
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> up[i][0];

    for (int j = 1; j < 32; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    while (q--)
    {
        int x, k;
        cin >> x >> k;
        for (int i = 0; i < 32; i++)
        {
            if (k & (1 << i))
            {
                x = up[x][i];
            }
        }
        cout << x << endl;
    }
    return 0;
}
