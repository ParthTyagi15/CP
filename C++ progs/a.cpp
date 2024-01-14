#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;

    s = s.substr(0, s.size() / 2);

    int k = unique(s.begin(), s.end()) - s.begin();

    cout << (k == 1 ? "NO\n" : "YES\n");
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
    8 1 2
    1000 0001 0010 -> 1011
    1011 1011 1011
    0011 1010 1001

*/
