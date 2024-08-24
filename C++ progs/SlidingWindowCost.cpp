#include<bits/stdc++.h>

using namespace std;

#define i64 int64_t

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<i64>nums(N);
    for(auto &x : nums)cin >> x;

    // MULTISET APPROACH FOR SLIDING WINDOW MEDIAN...
    multiset<i64>left, right;
    vector<i64>cost;
    i64 leftSum = 0, rightSum = 0;

    int i = 0;

    while(i < K) {
        left.insert(nums[i]);
        leftSum += nums[i];
        i++;
    }

    for(int j = 0; j < K / 2; j++){
        int val = *left.rbegin();
        left.erase(left.lower_bound(val));
        right.insert(val);
        leftSum -= val;
        rightSum += val;
    }

    while(1) {
        i64 median = *left.rbegin();
        i64 leftSize = left.size();
        i64 rightSize = right.size();
        i64 leftCost = leftSize * median - leftSum;
        i64 rightCost = rightSum - rightSize * median;
        cost.push_back(leftCost + rightCost);

        if(i >= N)break;

        int outgoing = nums[i - K];
        int incoming = nums[i];

        if(outgoing <= *left.rbegin()) {
            leftSum -= outgoing;
            left.erase(left.lower_bound(outgoing));
        }
        else{
            rightSum -= outgoing;
            right.erase(right.lower_bound(outgoing));
        }

        if(left.empty() == false and incoming <= *left.rbegin()) {
            leftSum += incoming;
            left.insert(incoming);
        }
        else{
            rightSum += incoming;
            right.insert(incoming);
        }

        if(left.size() > right.size()) {
            rightSum += *left.rbegin();
            leftSum -= *left.rbegin();
            right.insert(*left.rbegin());
            left.erase(left.lower_bound(*left.rbegin()));
        }
        if(right.size() > left.size()) {
            leftSum += *right.begin();
            rightSum -= *right.begin();
            left.insert(*right.begin());
            right.erase(right.lower_bound(*right.begin()));
        }

        i++;
    }

    for(auto x : cost)cout << x << " ";
    cout << "\n";

    return 0;
}