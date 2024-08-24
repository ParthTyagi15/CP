#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

#define endl "\n"
#define pii pair<int, int>
#define INF 1e15

const int maxN = 2e5 + 5;

ll N, Q;

int main()
{
    // freopen("hps.in", "r", stdin);
    // freopen("hps.out", "w", stdout);
    IOS;
    cin >> N >> Q;
    vector<ll>arr(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        if(i > 0){
            arr[i] ^= arr[i - 1];
        }
    }
    while(Q--){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        if(a == 0){
            cout << arr[b] << endl;
        }else{
            cout << (arr[b] ^ arr[a - 1]) << endl;
        }
    }
    return 0;
}