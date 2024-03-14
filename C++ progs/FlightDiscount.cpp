#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

const int maxN = (int)1e5;
vector<pair<ll, ll>> adj[maxN + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<ll> disc(n + 1, LLONG_MAX);
    pq.push({0, {1, 0}}); // dist, node, discount(0 if no discount used till now; 1 if discount used till now)

    while (!pq.empty())
    {
        ll d = pq.top().first;
        ll node = pq.top().second.first;
        ll discount = pq.top().second.second;

        pq.pop();

        if(discount == 0)
        {
            if(dist[node] < d)
                continue;
        }
        else
        {
            if(disc[node] < d)
                continue;
        }

        for (auto it : adj[node])
        {
            ll v = it.first;
            ll wt = it.second;
            if(discount == 0)
            {
                if(dist[v] > d + wt)
                {
                    dist[v] = d + wt;
                    pq.push({dist[v], {v, 0}});
                }
                if(disc[v] > d + wt / 2)
                {
                    disc[v] = d + wt / 2;
                    pq.push({disc[v], {v, 1}});
                }
            }
            else
            {
                if(disc[v] > d + wt)
                {
                    disc[v] = d + wt;
                    pq.push({disc[v], {v, 1}});
                }
            }
        }
    }
    cout << disc[n] << endl;
    return 0;
}
