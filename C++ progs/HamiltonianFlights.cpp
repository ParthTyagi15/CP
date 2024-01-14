#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAX_N = 20;
const ll MOD = (ll)1e9 + 7;

ll dp[1 << MAX_N][MAX_N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> adj[MAX_N];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[b - 1].push_back(a - 1);
    }

    dp[1][0] = 1;

    for(int s = 2; s < (1 << n); s++) {
        if(s & (1 << 0) == 0)continue; //if the starting city is not in the subset don't need to consider it
        if((s & (1 << (n - 1))) && s != ((1 << n) - 1))continue; //consider subsets with the last city if it's the full subset => ignore all instances of subsets that don't include the n−1-th city and are is not the subset that contains all cities

        for(int end = 0; end < n; end++) {
            if((s & (1 << end)) == 0)continue;

            int prev = s - (1 << end);//subset that doesn't include end city
            for(auto it : adj[end])//iterate over all the cities from where we can reach the end city
            {
                if((s & (1 << it)))//if those cities are in the set then ->
                {
                    dp[s][end] += dp[prev][it];
                    dp[s][end] %= MOD;
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << "\n";
    return 0;
}