#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin>>n;
    ll s = n*(n+1)/2;
    if(s%2!=0)
    {
        cout<<"NO\n";
    }
    else
    {
        if(n%4==0)
        {
            cout<<"YES\n";
            cout<<n/2<<"\n";
            for(int i = 1;i<=n/2;i+=2)
            cout<<i<<" "<<n-i+1<<" ";
            cout<<"\n";
            cout<<n/2<<"\n";
            for(int i = 2;i<=n/2;i+=2)
            cout<<i<<" "<<n-i+1<<" ";
            cout<<"\n";
        }
        else
        {
            cout<<"YES\n";
            cout<<n/2 + 1<<"\n";
            for(int i = 1;i<=n/2;i+=2)
            cout<<i<<" "<<n-i<<" ";
            cout<<"\n";
            cout<<(n/2)<<"\n";
            for(int i = 2;i<=n/2;i+=2)
            cout<<i<<" "<<n-i<<" ";
            cout<<n<<"\n";
        }
    }
    return 0;
}



/*
n = 1 : false - 1
n = 2 : false - 3
n = 3 : true - 6
    1 2 - 3
    3   - 3
n = 4 - 10
    1 4 - 5
    2 3 - 5
n = 5 : false - 15
n = 6 : false - 21
n = 7 : true - 28
    
*/