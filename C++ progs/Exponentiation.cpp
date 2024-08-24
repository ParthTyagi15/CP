#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define i64 int64_t
#define all(v) v.begin(), v.end()

const i64 mod = 1e9 + 7;

i64 binpow(i64 a, i64 b) {
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

    int TC;
    cin >> TC;
    while(TC--) {
        i64 a, b;
        cin >> a >> b;

        cout << binpow(a, b) << endl;
    }
    return 0;
}