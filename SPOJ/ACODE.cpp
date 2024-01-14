#include<bits/stdc++.h>
using namespace std;

int dp[100001];

int findWays(string s,int idx){
    if(idx == s.size())return 1;
    if(idx > s.size())return 0;
    if(s[idx] == '0')return 0;
    if(dp[idx] != -1)return dp[idx];

    int op1 = 0,op2 = 0;

    // take two characters for decoding
    if(idx + 1 < s.size()){
        if(s[idx] == '1')op1 += findWays(s,idx + 2);
        else if(s[idx] == '2' and s[idx + 1] <= '6')op1 = findWays(s,idx + 2);
    }

    // take one character for decoding

    op2 = findWays(s,idx + 1);

    return dp[idx] = op1 + op2;
}

void solve(){
    for(;;){
        string n;
        cin >> n;
        if(n == "0")return;
        memset(dp,-1,sizeof(dp));
        cout << findWays(n,0) << endl;
    }
}

int main()
{
    int t = 1;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cin >> t;       
    while(t--){
        solve();
    }
    return 0;
}