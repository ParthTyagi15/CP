#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{

    // TLE -> need to optimization
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, X;
    cin >> N >> X;

    vector<ll>price(N, 0), pages(N, 0), copies(N, 0);

    for(ll i = 0; i < N; i++)cin >> price[i];
    for(ll i = 0; i < N; i++)cin >> pages[i];
    for(ll i = 0; i < N; i++)cin >> copies[i];

    ll dp[N + 1][X + 1];
    memset(dp, 0ll, sizeof(dp));

    // dp[0][0] = 1;

    for(ll j = 1; j <= X; j++){
        for(ll i = 1; i <= N; i++){
            dp[i][j] = dp[i - 1][j];
            for(ll k = 1; k <= copies[i - 1]; k++){
                if(j - k * price[i - 1] >= 0){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k * price[i - 1]] + k * pages[i - 1]);
                }
            }
        }
    }
    cout << dp[N][X] << endl;
    return 0;
}