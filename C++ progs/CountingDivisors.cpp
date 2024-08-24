#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define i64 int64_t
#define all(v) v.begin(), v.end()

const int maxN = 1e6 + 5;

i64 d[maxN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(d, 0, sizeof(d));
    for(i64 i = 1; i <= maxN; i++) {
        for(i64 j = i; j <= maxN; j += i) {
            d[j]++;
        }
    }
    int TC;
    cin >> TC;
    while(TC--) {
        i64 X;
        cin >> X;
        cout << d[X] << endl;
    }
    return 0;
}