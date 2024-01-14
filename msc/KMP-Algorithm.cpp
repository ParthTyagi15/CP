#include<bits/stdc++.h>
using namespace std;

vector<int> computePrefixSuffix(string pat){
    int m = pat.size();
    vector<int>lps(m);
    int j = 0;
    for(int i = 1; i < m; i++){
        while(j > 0 and pat[j] != pat[i]){
            j = lps[j - 1];
        }
        if(pat[i] == pat[j]){
            lps[i] = ++j;
        }
        else{
            lps[i] = j;
        }
    }
    return lps;
}

void KMP(string str, string pat){
    int n = str.size();
    int m = pat.size();
    vector<int>lps = computePrefixSuffix(pat);
    int j = 0;
    for(int i = 0; i < n; i++){
        while(j > 0 and pat[j] != str[i]){
            j = lps[j - 1];
        }
        if(str[i] == pat[j]){
            ++j;
        }
        if(j == m){
            cout << i - m + 1 << "\n";
            j = lps[j - 1];
        }
    }
}

int main()
{
    string str, pat;
    cin >> str >> pat;
    KMP(str,pat);
    return 0;
}