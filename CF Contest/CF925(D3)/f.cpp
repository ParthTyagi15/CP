#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast, avx2")
typedef long long ll;
typedef double long dl;
#define mod 1000000007
#define mod2 998244353
#define PI 3.141592653589793238
// #define setbits(x) __builtin_popcountll(x)
// #define zrobits(x) __builtin_ctzll(x)
#define sz(x) (ll)(x).size()
#define deci(x, y) fixed << setprecision(y) << x
#define all(a) a.begin(), a.end()
#define dbg(x) cout << #x << "=" << x << "\n"
#define dbg2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
#define dbg3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << "\n"
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
// #define sort(a) sort(all(a))
#define flip(a) reverse(all(a))
#define rev(a) sort(a.begin(), a.end(), greater<ll>())
#define sum(a) accumulate(all(a), 0)
#define add(a, i, k) accumulate(a.begin() + i, a.begin() + k, 0)
#define parth                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void test_cases()
{
    // yaha likhna hai code
    int n, k;
    cin >> n >> k;
    vector<int> adj[n + 1];
    vector<int> vis(n + 1, 0);
    vector<int> pathVis(n + 1, 0);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < k; i++)
    {
        vector<int> v(n);
        for (int j = 0; j < n; j++)
            cin >> v[j];
        for (int j = 1; j + 1 < n; j++)
        {
            adj[v[j]].push_back(v[j + 1]);
            indeg[v[j + 1]]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        for (auto it : adj[node])
        {
            indeg[it]--;
            if (indeg[it] == 0)
                q.push(it);
        }
    }
    if (cnt == n)
    {
        Yes;
    }
    else
        No;
}

int main()
{
    ll tt = 1;
    parth;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> tt;
    while (tt--)
    {
        test_cases();
    }
    return 0;
}