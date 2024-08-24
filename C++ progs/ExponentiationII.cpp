#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define i64 int64_t
#define all(v) v.begin(), v.end()



i64 binpow(i64 a, i64 b, i64 mod) {
    a %= mod;
    i64 res = 1;
    while(b > 0) {
        if(b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const i64 mod = 1e9 + 7;
    int TC;
    cin >> TC;
    while(TC--) {
        i64 a, b, c;
        cin >> a >> b >> c;

        cout << binpow(a, binpow(b, c, mod - 1), mod) << endl;
    }
    return 0;
}