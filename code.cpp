#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast, avx2")
typedef long long ll;
typedef double long dl;
typedef int64_t i64;
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
#define vi vector<int>
#define vl vector<ll>
#define vi64 vector<i64>
#define vc vector<char>
#define vs vector<string>
#define vd vector<dl>
#define vpi64 vector<pair<i64, i64>>
#define vpl vector<pair<ll, ll>>
#define vtl vector<tuple<ll, ll, ll>>
typedef pair<ll, ll> pl;
#define pb push_back
#define F first
#define S second
// #define mp make_pair
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

template <typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1)
{
    if (start < 0)
        start = 0;
    if (end < 0)
        end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void test_cases()
{
    i64 N, X;
    cin >> N >> X;
    vi64 A(N);
    take(A);
    i64 left = 0, right = 0;
    i64 sum = 0, ans = N + 2;
    while(right < N) {
        sum += A[right];
        while(sum >= X) {
            ans = min(ans, right - left + 1);
            sum -= A[left];
            left++;
        }
        right++;
    }
    if(ans == N + 2) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

int main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    parth;
    ll tt = 1;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // cin >> tt;
    while (tt--)
    {
        test_cases();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}