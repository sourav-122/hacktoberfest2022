#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("div7.in","r",stdin);
    freopen("div7.out","w",stdout);
    int n,mod,mx=1;
    cin>>n;

    int a[8];
    for(int i=0;i<8;i++)
    {
            a[i]=-1;
    }

    long long int ar[n+6];
    for(int i=1;i<=n;i++)cin>>ar[i];

    mod=ar[1]%7;
    a[mod]=1;

    for(int i=2;i<=n;i++)
    {
        ar[i]+=ar[i-1];

        mod=ar[i]%7;
        if(mod==0)
        {
            mx=max(mx,i);
        }
        if(a[mod]==-1)
        {
            a[mod]=i;
        }
        else{
            mx=max(mx,i-a[mod]);
        }
    }
    cout<<mx<<endl;

}
