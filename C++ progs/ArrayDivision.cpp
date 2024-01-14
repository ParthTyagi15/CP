#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int>a;
ll n,m;

bool check(ll mid){
	ll sum = 0,cnt = 1;
	for(int i = 0; i < a.size(); i++){
		if(a[i] > mid)return false;
		if(sum + a[i] <= mid){
			sum += a[i];
		}
		else{
			sum = a[i];
			cnt++;
		}
	}

	return cnt <= m;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> m;
	a.resize(n);
	ll sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	ll lo = *min_element(a.begin(),a.end());
	ll hi = sum;

	ll ans = -1;
	while(lo <= hi){
		ll mid = (hi - lo)/2 + lo;
		if(check(mid)){
			ans = mid;
			hi = mid - 1;
		}
		else{
			lo = mid + 1;
		}
	}
	cout << ans << "\n";
}