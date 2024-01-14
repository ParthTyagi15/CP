#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    // use a map to avoid using a very large array
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        // target minus a number is the other number
        if (mp.count(x - values[i]))
        {
            cout << i + 1 << " " << mp[x - values[i]] << endl;
            return 0;
        }
        mp[values[i]] = i + 1;
    }

    cout << "IMPOSSIBLE" << endl;
}