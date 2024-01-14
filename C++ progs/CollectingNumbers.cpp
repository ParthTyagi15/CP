#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        v[x] = i;
    }
    int cnt = 1;
    for (int i = 2; i <= n; i++)
    {
        if (v[i - 1] > v[i])
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}