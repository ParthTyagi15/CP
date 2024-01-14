#include<bits/stdc++.h>
using namespace std;

void solve(){
    for(;;){
        int n;
        cin >> n;
        if(n == 0)return ;

        set<string>s;
        for(int i = 0; i < n; i++){
            string t;
            cin >> t;
            s.insert(t);
        }

        for(;;){
            string test;
            cin >> test;
            cin.ignore();

            string phrase;
            getline(cin, phrase);
            if(phrase == "CASE")break;

            istringstream iss(phrase);
            vector<string>words;
            for(;;){
                string word;
                iss >> word;
                if(word == "")break;
                if(s.find(word) == s.end()){
                    words.push_back(word);
                }
            }

            int dp[200][200];
            memset(dp,0,sizeof(dp));
            dp[0][0] = 1;
            int dp2[200][200];
    
            for(int i = 0; i < words.size(); i++){
                for(int j = 0; j < test.size(); j++){
                    int left = min(test.length() - j, words[i].length());

                    for(int k = 0; k < words[i].size(); k++){
                        dp2[k][0] = 1;
                    }
                    for(int k = 1; k <= left; k++){
                        dp2[0][k] = 0;
                    }
                    for(int k = 0; k < words[i].length(); k++){
                        for(int m = 0; m < left; m++){
                            dp2[k + 1][m + 1] = dp2[k][m + 1]; // not take the kth character of the ith word as an acronym
                            if(words[i][k] == tolower(test[j + m])){
                                dp2[k + 1][m + 1] += dp2[k][m];
                            }
                        }
                    }

                    for(int k = 1; k <= left; k++){
                        dp[i + 1][j + k] += dp[i][j] * dp2[words[i].length()][k];
                    }
                }
            }

            if(dp[words.size()][test.size()] == 0){
                cout << test << " is not a valid abbreviation\n";
            }
            else{
                cout << test << " can be formed in " << dp[words.size()][test.size()] << " ways\n";
            }

        }
    }
}

int main()
{
    int t = 1;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cin >> t;       
    while(t--){
        solve();
    }
    return 0;
}