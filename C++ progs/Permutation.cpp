#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll n;
    cin >> n;
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    if(n<=3)
    {
        cout<<"NO SOLUTION\n";
    }
    else if(n==4)
    {
        cout<<"2 4 1 3"<<endl;
    }
    else
    {
        for(int i=1;i<=n;i+=2)
        {
            cout<<i<<" ";
        }
        for(int i = 2;i<=n;i+=2)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }       
    return 0;
}