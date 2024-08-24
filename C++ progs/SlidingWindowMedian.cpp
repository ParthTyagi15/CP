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

    // MULTISET APPROACH...
    multiset<i64>left, right;
    vector<i64>medians;

    int i = 0;

    while(i < K) {
        left.insert(nums[i]);
        i++;
    }

    for(int j = 0; j < K / 2; j++){
        int val = *left.rbegin();
        left.erase(left.lower_bound(val));
        right.insert(val);
    }

    while(1) {
        medians.push_back(*left.rbegin());

        if(i >= N)break;

        int outgoing = nums[i - K];
        int incoming = nums[i];

        if(outgoing <= *left.rbegin()) {
            left.erase(left.lower_bound(outgoing));
        }
        else{
            right.erase(right.lower_bound(outgoing));
        }

        if(left.empty() == false and incoming <= *left.rbegin()) {
            left.insert(incoming);
        }
        else{
            right.insert(incoming);
        }

        if(left.size() > right.size()) {
            right.insert(*left.rbegin());
            left.erase(left.lower_bound(*left.rbegin()));
        }
        if(right.size() > left.size()) {
            left.insert(*right.begin());
            right.erase(right.lower_bound(*right.begin()));
        }

        i++;
    }

    for(auto x : medians)cout << x << " ";
    cout << "\n";


    // PRIORITY QUEUE APPROACH -> LAZY DELETION...
    /*
    vector<int> medians;
    unordered_map<int, int> mp;
    priority_queue<int>max_heap; // stores number to the left of median
    priority_queue<int, vector<int>, greater<int>> min_heap; // stores number to the right of median

    // initializing the first window...

    int i = 0;
    while(i < K) {
        max_heap.push(nums[i]);
        i++;
    }

    for(int j = 0; j < K / 2; j++) {
        min_heap.push(max_heap.top());
        max_heap.pop();
    }

    while(1) {
        medians.push_back(max_heap.top());

        if(i >= nums.size())break;

        int outgoing = nums[i - K];
        int incoming = nums[i];
        i++;
        int balance = 0;

        // if balance < 0 -> max_heap has a lesser size... => the element was deleted from max_heap(left of median)
        // if balance > 0 -> vice versa...
        balance += (outgoing <= max_heap.top()) ? -1 : 1;


        // map mp will store the elements that are to be deleted...
        // we will delete them later, when they somehow end up on the top of the maxHeap or minHeap...
        mp[outgoing]++;

        if(max_heap.empty() == false and incoming <= max_heap.top()) {
            balance++;
            max_heap.push(incoming);
        }
        else{
            balance--;
            min_heap.push(incoming);
        }

        // we will rearrange the size of heaps, according to the balance variable...
        if(balance < 0) {
            max_heap.push(min_heap.top());
            min_heap.pop();
            balance++;
        }
        if(balance > 0) {
            min_heap.push(max_heap.top());
            max_heap.pop();
            balance--;
        }

        // now we will delete the elements that are in maxHeap and minHeap and also are in map...
        while(mp[max_heap.top()]){
            mp[max_heap.top()]--;
            max_heap.pop();
        }

        while(min_heap.empty() == false and mp[min_heap.top()]){
            mp[min_heap.top()]--;
            min_heap.pop();
        }
    }

    for(auto x : medians)cout << x << " ";
    cout << "\n";
    */
    return 0;
}