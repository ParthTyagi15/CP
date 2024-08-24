#include <bits/stdc++.h>

using namespace std;

#define i64 int64_t

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, X;
    cin >> N >> X;
    map<i64, int> mp;
    i64 a = 0;
    mp[0] = 1;
    i64 sum = 0, res = 0;
    for(int i = 0; i < N; i++){
        cin >> a;
        sum += a;
        res += mp[sum - X];
        mp[sum]++;
    }
    cout << res << "\n";
    return 0;
}
