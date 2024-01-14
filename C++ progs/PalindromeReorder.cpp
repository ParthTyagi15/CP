#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int freq[26] = {};

    for (char c : s)
    {
        freq[(int)(c - 'A')]++;
    }
    int mid = -1;
    for (int i = 0; i < 26; i++)
    {
        // cout<<freq[i]<<" ";
        if (freq[i] & 1)
        {
            if (mid != -1)
            {
                cout << "NO SOLUTION\n";
                return 0;
            }
            else
            {
                mid = i;
            }
        }
    }
    // cout<<endl;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < freq[i] / 2; j++)
        {
            cout << (char)(i + 'A');
        }
    }
    if (mid != -1)
    {
        cout << (char)(mid + 'A');
    }
    for (int i = 25; i >= 0; i--)
    {
        for (int j = 0; j < freq[i] / 2; j++)
        {
            cout << (char)(i + 'A');
        }
    }
    cout << endl;
    return 0;
}