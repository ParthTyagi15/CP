#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast, avx2")
typedef long long ll;
typedef double long dl;
#define mod 1000000007
#define mod2 998244353
#define PI 3.141592653589793238
//#define setbits(x) __builtin_popcountll(x)
//#define zrobits(x) __builtin_ctzll(x)
#define sz(x) (ll)(x).size()
#define deci(x, y) fixed<<setprecision(y)<<x
#define all(a) a.begin(),a.end()
#define dbg(x) cout<<#x<<"="<<x<<"\n"
#define dbg2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<"\n"
#define dbg3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<"," <<#z<<"="<<z<<"\n"
#define mem0(x) memset(x,0,sizeof x)
#define mem1(x) memset(x,-1,sizeof x)
#define find(a,x) find(all(a),x)
#define bs(a,x) binary_search(all(a),x)
#define lb(a,x) lower_bound(all(a),x)
#define ub(a,x) upper_bound(all(a),x)
#define gcd __gcd
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define Yes cout<<"Yes\n"
#define No cout<<"No\n"
#define nl cout<<"\n"
#define endl "\n"
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rep2(i,a,b,k) for(ll i=a;i<b;i+=k)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define per2(i,a,b,k) for(ll i=a;i>=b;i-=k)
#define take(a) rep(i,0,sz(a)) cin>>a[i]
#define print(a) rep(i,0,sz(a)) cout<<a[i]<<" "
#define vl vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vd vector<dl>
#define vpl vector<pair<ll,ll>>
#define vtl vector<tuple<ll,ll,ll>>
typedef pair<ll,ll> pl;
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define mine(a) *min_element(all(a))
#define maxe(a) *max_element(all(a))
#define sort(a) sort(all(a))
#define flip(a) reverse(all(a))
#define rev(a) sort(a.begin(),a.end(),greater<ll>())
#define sum(a) accumulate(all(a),0)
#define add(a,i,k) accumulate(a.begin()+i,a.begin()+k,0)

void solve(int v, vector<int>&vis, stack<int>&st, vector<vector<int>>&adj){
    vis[v] = 1;

    for(auto it : adj[v]){
        if(!vis[it]){
            solve(it,vis,st,adj);
        }
    }
    st.push(v);
}

void test_cases(){
    // yaha likhna hai code 
    int n,m;
    cin >> n >> m;
    vl a(n);
    int offset = 0;
    unordered_map<int,int>distinct;
    rep(i,0,n){
        cin >> a[i];
        distinct[a[i]]++;
    }
    // for(int i = 0; i < n; i++){

    // }
    for(auto it : distinct){
        if(it.second > 1){
            offset++;
        }
    }
    // cout << "offset: " << offset << endl;
    vector<vector<int>>adj(n);
    vector<int>indeg(n,0);
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        u--,v--;
        if(a[u] >= a[v]){
            adj[v].push_back(u);
            indeg[u]++;
        }
        else{
            adj[u].push_back(v);
            indeg[v]++;
        }
    }
    int src = 0;

    stack<int>st;
    vector<int>dist(n,-1e9);
    vector<int>vis(n,0);

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            solve(i,vis,st,adj);
        }
    }
    dist[src] = 1;

    while(st.size() > 0){
        int node = st.top();
        st.pop();
        // cout << "node: " << node << endl;
        if(dist[node] != -1e9){
            for(auto it : adj[node]){
                // if(dist[it] < dist[node] + 1){
                //     dist[it] = dist[node] + 1;
                // }
                dist[it] = max(dist[it], dist[node] + (a[it] != a[node]));
            }
        }
    }
    // for(auto it : dist){
    //     cout << it << " ";
    // }
    // cout << endl;
    if(dist[n - 1] <= 0){
        cout << 0 << endl;
    }
    else{
        cout << dist[n - 1]  << endl;
    }
}
int main(){
    ll tt = 1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    // cin>>tt;
    while(tt--){
        test_cases();
    }
return 0;
}