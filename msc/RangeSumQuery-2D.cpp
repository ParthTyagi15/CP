#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>>mat(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    
    vector<vector<int>>prefix(n + 1,vector<int>(m + 1,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            prefix[i + 1][j + 1] = prefix[i][j + 1] + prefix[i + 1][j] + mat[i][j] - prefix[i][j];
        }
    }

    int q;
    cin >> q;
    while(q--){
        int row1,col1,row2,col2;
        cin >> row1 >> col1 >> row2 >> col2;

        cout << prefix[row2+1][col2+1] - prefix[row1][col2+1] - prefix[row2 + 1][col1] + prefix[row1][col1] << endl;
    }
    return 0;
}