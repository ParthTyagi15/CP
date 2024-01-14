#include <bits/stdc++.h>
using namespace std;

const int maxN = 100005;
const int LOG = 17;
int arr[maxN];
int table[maxN][LOG];

int query(int L, int R){
    int len = R - L + 1;
    int k = 31 - __builtin_clz(len);
    return min(table[L][k], table[R - (1 << k) + 1][k]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    // table[idx][length of subarray in power of 2]
    // 1) Input
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        table[i][0] = arr[i]; //length 1 minimum values
    }
    // 2) preprocessing
    for(int j = 1; j < LOG; j++){
        for(int i = 0; i + (1 << j) - 1 < N; i++){
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
    // 3) Answer queries
    int q;
    cin >> q;
    while(q--){
        int L,R;
        cin >> L >> R;
        cout << query(L,R) << "\n";
    }
    return 0;
}