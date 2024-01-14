#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    multiset<int> st;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        auto it = st.upper_bound(k);
        if (it != st.end())
            st.erase(it);
        st.insert(k);
    }
    cout << (int)st.size() << endl;
    return 0;
}