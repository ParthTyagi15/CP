#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
long long pow(int x)
{
    ll res = 1;
    ll a = 2;
    while (x > 0)
    {
        if (x & 1)
            res = res * a % MOD;
        a = (a * a) % MOD;
        x = x >> 1;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    cout << pow(n) << endl;
    return 0;
}