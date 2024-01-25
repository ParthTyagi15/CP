#include <bits/stdc++.h>
using namespace std;



void rabin_karp(string patt, string text)
{
    const int p = 53;
    const int mod = (int)1e9 + 9;
    int n = text.size(), m = patt.size();
    // cout << patt << " " << text << endl;
    //calculate the polynomial p^i
    vector<long long> p_pow(max(n, m));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i - 1] * p) % mod;

    
    //calculate the hash value
    vector<long long>h(n + 1, 0);
    for(int i = 0; i < n; i++)
        h[i + 1] = (h[i] + (text[i] - 'A' + 1) * p_pow[i]) % mod;
    
    long long h_patt = 0;
    for(int i = 0; i < m; i++){
        h_patt = (h_patt + (patt[i] - 'A' + 1) * p_pow[i]) % mod;
    }
    
    vector<int>occurrences;
    for(int i = 0; i + m - 1 < n; i++){
        long long curr_h = (h[i + m] - h[i] + mod) % mod;
        if(curr_h == h_patt * p_pow[i] % mod)
            occurrences.push_back(i);
    }
    for(auto it : occurrences){
        cout << it << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text = "AABAACAADAABAABA";
    string patt = "AABA";
    rabin_karp(patt,text);
    cout << endl;
    return 0;
}