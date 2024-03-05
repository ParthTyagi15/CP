#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<ll>arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    arr.resize(n);
    for(auto &it : arr){
        cin >> it;
    }
    stack<ll>st;
    for(int i = 0; i < n; i++){
        // if(st.empty()){
        //     cout << 0 << " ";
        //     st.push(i);
        //     continue;
        // }
        while(!st.empty() and arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            cout << 0 << " ";
        }
        else{
            cout << st.top() + 1 << " ";
        }
        st.push(i);
    }
    cout << "\n";
    return 0;
}
