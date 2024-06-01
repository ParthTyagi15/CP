#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define IO                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int main()
{
    IO;
    int n;
    cin >> n;
    vector<string> v(n);
    int mxLen = 0;
    for (auto &it : v)
    {
        cin >> it;
    }
    vector<vector<int>> adj(26);
    vector<int> indegree(26, 0);
    bool flag = false;
    for (int i = 0; i < n - 1; i++)
    {
        string word1 = v[i];
        string word2 = v[i + 1];
        int tmp = 0;
        for (int j = 0; j < min(word1.size(), word2.size()); j++)
        {
            if(word1[j] == word2[j])
            tmp++;
            if (word1[j] != word2[j])
            {
                adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                break;
            }
            if(word1.size() > word2.size() and tmp == min(word1.size(), word2.size())){
                flag = true;
            }
        }
    }
    if(flag){
        cout << "Impossible\n";
        return 0;
    }
    for (int i = 0; i < 26; i++)
    {
        for (auto &it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if (indegree[i] == 0)
        {
            // cout << "Inside this loop: \n";
            q.push(i);
        }
    }
    string ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans += (char)(node + 'a');
        for (auto &it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (indegree[i] != 0)
        {
            cout << "Impossible\n";
            return 0;
        }
    }
    cout << ans << "\n";
    return 0;
}
