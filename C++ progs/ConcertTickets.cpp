#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    multiset<int> price;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        price.insert(-a);
    }
    for (int i = 0; i < m; i++)
    {
        // multiset lower bound returns the first element equal in the multiset, if element is not present then it return next element just greater than the key.
        int x;
        cin >> x;
        if (price.lower_bound(-x) == price.end())
            cout << -1 << "\n";
        else
        {
            cout << -(*price.lower_bound(-x)) << "\n";
            price.erase(price.lower_bound(-x));
        }
    }
    return 0;
}