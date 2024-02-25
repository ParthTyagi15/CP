#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    cnt += (s[0] == '.' ? 1 : 0);
    cnt += (s[1] == '.' ? 1 : 0);
    for(int i = 2; i < n; i++){
        if(s[i] == '.' and s[i-1] == '.' and s[i-2] == '.'){
            cout << 2 << endl;
            return;
        }
        else if(s[i] == '.'){
            cnt++;
        }
    }
    cout << cnt << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
