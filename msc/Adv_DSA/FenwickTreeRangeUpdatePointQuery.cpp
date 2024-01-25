#include <bits/stdc++.h>

using namespace std;

class FenwickTree {
public:
    FenwickTree(int sz) : N(sz), tree(sz + 1, 0) {}

    FenwickTree(vector<long> values) : N(values.size()), tree(N + 1, 0) {
        if (values.empty()) {
            throw invalid_argument("Values vector cannot be empty!");
        }
        values.insert(values.begin(), 0);

        for (int i = 1; i <= N; i++) {
            int parent = i + lsb(i);
            if (parent <= N) {
                tree[parent] += values[i];
            }
        }
    }
    long sum(int left, int right) {
        if (right < left) {
            throw invalid_argument("Make sure right >= left");
        }
        return prefixSum(right) - prefixSum(left - 1);
    }
    long get(int i) {
        return sum(i, i);
    }
    void add(int i, long v) {
        while (i <= N) {
            tree[i] += v;
            i += lsb(i);
        }
    }
    void set(int i, long v) {
        add(i, v - sum(i, i));
    }
    void display(){
        for(int i = 1; i <= N; i++){
            cout << tree[i] << " ";
        }
        cout << endl;
    }
private:
    int N;
    vector<long> tree;

    int lsb(int i) {
        return i & -i;
    }

    long prefixSum(int i) {
        long sum = 0;
        while (i != 0) {
            sum += tree[i];
            i -= lsb(i);
        }
        return sum;
    }
};

int main() {
    // Example usage of the Fenwick Tree
    vector<long> values = {0, 1, 2, 3, 4, 5};
    FenwickTree ft(values);

    cout << "Fenwick Tree: ";
    ft.display();
    cout << endl;

    cout << "Sum [2, 4]: " << ft.sum(2, 4) << endl;
    cout << "Get value at index 3: " << ft.get(3) << endl;

    ft.add(3, 2);
    cout << "After adding 2 to index 3: ";
    ft.display();
    cout << endl;

    ft.set(2, 6);
    cout << "After setting index 2 to 6: ";
    ft.display();
    cout << endl;

    return 0;
}
