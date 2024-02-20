#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

const int INF = 1000000007;
typedef long long ll;
typedef double long dl;
#define mem0(x) memset(x, 0, sizeof x)
#define mem1(x) memset(x, -1, sizeof x)
#define bs(a, x) binary_search(all(a), x)
#define lb(a, x) lower_bound(all(a), x)
#define ub(a, x) upper_bound(all(a), x)
#define gcd __gcd
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define nl cout << "\n"
#define endl "\n"
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rep2(i, a, b, k) for (ll i = a; i < b; i += k)
#define per(i, a, b) for (ll i = a; i >= b; i--)
#define per2(i, a, b, k) for (ll i = a; i >= b; i -= k)
#define take(a) rep(i, 0, sz(a)) cin >> a[i]
#define print(a) rep(i, 0, sz(a)) cout << a[i] << " "
#define vl vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vd vector<dl>
#define vpl vector<pair<ll, ll>>
#define vtl vector<tuple<ll, ll, ll>>
typedef pair<ll, ll> pl;
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define mine(a) *min_element(all(a))
#define maxe(a) *max_element(all(a))

int x[MAXN];

int y[MAXN];

int z[MAXN];

int main()
{

    int n, m, ans, y0, y1;

    cin >> n >> m >> y0 >> y1;

    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }
    y[0] = -INF;
    for (int i = 1; i <= m; ++i)
    {
        cin >> y[i];
    }
    y[m + 1] = INF;

    m += 2;

    fill(z, z + m, INF);

    ans = 0;

    for (int i = 0; i < n; ++i)

    {

        int j = lower_bound(y, y + m, x[i]) - y;

        int d = min(x[i] - y[j - 1], y[j] - x[i]);

        if (y[j] - x[i] > d || (x[i] - y[j - 1] == d && (z[j - 1] == INF || z[j - 1] == d)))
            --j;

        if (z[j] == INF || z[j] == d)
            ++ans;

        z[j] = min(z[j], d);
    }

    cout << n - ans << "\n";
    return 0;
}
