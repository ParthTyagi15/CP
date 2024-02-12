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
#define find(a, x) find(all(a), x)
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
#define rev(a) sort(a.begin(), a.end(), greater<ll>())
// #define sort(a) sort(all(a))
#define flip(a) reverse(all(a))
#define sum(a) accumulate(all(a), 0)
#define add(a, i, k) accumulate(a.begin() + i, a.begin() + k, 0)

void solve(vector<int> &arr, int l, int r)
{
    l--;
    r--;
    if (arr[l] > r)
    {
        cout << "-1 -1" << endl;
    }
    else
    {
        cout << l + 1 << " " << 1 + arr[l] << "\n";
    }
}

void test_cases()
{
    // yaha likhna hai code
    int n;
    cin >> n;
    vector<int> distinct(n, n);
    vector<int> arr(n);
    for (auto &it : arr)
        cin >> it;
    per(i, n - 2, 0)
    {
        if (arr[i] == arr[i + 1])
        {
            distinct[i] = distinct[i + 1];
        }
        else
        {
            distinct[i] = i + 1;
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        solve(distinct, l, r);
    }
    cout << endl;
}

int main()
{
    ll tt = 1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> tt;
    while (tt--)
    {
        test_cases();
    }
    return 0;
}