#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,x;
vector<pair<ll,ll>>arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        arr[i].first = a;
        arr[i].second = i + 1;
    }
    if(n <= 3){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    sort(arr.begin(),arr.end());
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int front = j + 1;
            int back = n - 1;
            while(front < back){
                if(arr[i].first + arr[j].first + arr[front].first + arr[back].first < x){
                    front++;
                }
                else if(arr[i].first + arr[j].first + arr[front].first + arr[back].first > x){
                    back--;
                }
                else{
                    cout << arr[i].second << " " << arr[j].second << " " << arr[front].second << " " << arr[back].second << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
