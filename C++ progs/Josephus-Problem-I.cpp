#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> v, int idx)
{
    if (v.size() == 1)
    {
        cout << v[0] << endl;
        return;
    }

    idx = (idx + 1) % v.size();

    auto it = v.begin() + idx;
    cout << *it << " ";

    v.erase(it);

    solve(v, idx);
}

int main()
{
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    solve(v, 0);
    return 0;
}