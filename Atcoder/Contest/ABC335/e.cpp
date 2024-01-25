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
// #define sort(a) sort(all(a))
#define flip(a) reverse(all(a))
#define rev(a) sort(a.begin(), a.end(), greater<ll>())
#define sum(a) accumulate(all(a), 0)
#define add(a, i, k) accumulate(a.begin() + i, a.begin() + k, 0)

const int maxN = 200005;
vector<int>adj[maxN];

void test_cases()
{
    // yaha likhna hai code
    int n,m;
    cin >> n >> m;
    vector<int>cost(n + 1);
    rep(i,1,n + 1)cin >> cost[i];

    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>dist(n + 1,-1e9);
    // negative because using max heap instead of min heap
    priority_queue<vector<int>>pq; // {cost,dis,node}

    pq.push({-cost[1],dist[1] = 1,1});

    while(!pq.empty()){
        auto it = pq.top();
        int val = it[0];
        int dis = it[1];
        int node = it[2];
        pq.pop();
        if(dist[node] < dis)continue;

        for(auto v : adj[node]){
            if(cost[v] < cost[node])continue;
            int tmp = dist[node] + (cost[node] < cost[v]);
            if(tmp > dist[v]){
                pq.push({-cost[v],dist[v] = tmp,v});
            }
        }
    }
    cout << max(0,dist[n]) << endl;
}

int main()
{
    ll tt = 1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // cin >> tt;
    while (tt--)
    {
        test_cases();
    }
    return 0;
}