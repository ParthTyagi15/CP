#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve()
{
    int n;
    cin >> n;
    vector<vector<int>>arr(n + 1,vector<int>(3,0));
    for(int i = 1; i <= n; i++){
        cin >> arr[i][1] >> arr[i][0] >> arr[i][2];
    }
    
    sort(arr.begin() + 1,arr.end());

    vector<int>lastDate(n + 1);
    for(int i = 1; i <= n; i++){
        lastDate[i] = arr[i][0];
        // cout << lastDate[i] << " ";
    }
    // cout << "\n";
    // cout << *lower_bound(lastDate.begin(),lastDate.end(),2) << endl;
    vector<ll>dp(n + 1,0);
    for(int i = 1; i <= n; i++){
        int idx = lower_bound(lastDate.begin(),lastDate.end(),arr[i][1]) - lastDate.begin();
        idx--;
        // cout << idx << " ";
        dp[i] = max(dp[i - 1], dp[idx] + arr[i][2]);
    }
    // cout << "\n";
    cout << dp[n] << endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
