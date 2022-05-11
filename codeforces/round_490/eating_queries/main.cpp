#include<bits/stdc++.h>
 
using namespace std;
 
const int N=2e5+5;
 
int T,n,q;
int a[N],sum[N];
 
bool cmp(int x,int y){
    return x>y;
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif

    cin>>T;

    while(T--){

        cin>>n>>q;

        for(int i=1;i<=n;++i) cin>>a[i];

        sort(a+1,a+n+1,cmp);

        for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];

        while(q--){
            int x;
            cin>>x;
            int pos=lower_bound(sum+1,sum+n+1,x)-sum;
            if(pos==n+1) cout<<-1<<endl;
            else cout<<pos<<endl;
        }
    }
    return 0;
}
