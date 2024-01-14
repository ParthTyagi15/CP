#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;

    set<int> lights{0, n};
    multiset<int> dist{n};

    for (int i = 0; i < x; i++)
    {
        int pos;
        cin >> pos;

        auto it1 = lights.upper_bound(pos);
        auto it2 = it1;
        it2--;

        // cout << *it1 << " " << *it2 << "\n";
        dist.erase(dist.find(*it1 - *it2));

        // cout << pos << " " << *it2 << "\n";
        dist.insert(pos - *it2);
        // cout << *it1 << " " << pos << " \n";
        dist.insert(*it1 - pos);
        lights.insert(pos);

        auto ans = dist.end();
        --ans;
        cout << *ans << " ";
    }
    cout << endl;
    return 0;
}