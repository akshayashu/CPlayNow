#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(int a[], int n, int k, int sum){
	
	if( k >= sum ){
		cout<<"Sorry, we can only supply "<<sum-1<<" oranges\n";
		
		for (int i = 0; i < n; ++i)
		{
			cout<<a[i]<<" ";
			if(k >= a[i] && i == n-1){
				cout<<a[i]-1<<" "<<"1\n";
			} else if(k > a[i]){
				cout<<a[i]<<" "<<"0\n";
			} else {
				cout<<k<<" "<<a[i]-k<<"\n";
			}
			k -= a[i];
		}
	} else{
		cout<<"Thank you, your order for "<<k<<" oranges are accepted\n";
		
		for (int i = 0; i < n; ++i)
		{
			if(k>a[i]){
				cout<<a[i]<<" "<<a[i]<<" "<<"0\n";
			}
			else if(0 < k <= a[i]){
				cout<<a[i]<<" "<<k<<" "<<a[i]-k<<"\n";
			}
			k -= a[i];
			if(k<0){
				k = 0;
			}
		}
	}

}

int main(){
	
	int m, k;
	int sum=0;
	cin>>m>>k;

	int a[m];
	for (int i = 0; i < m; ++i)
	{
		cin>>a[i];
		sum += a[i];
	}
	solve(a,m,k, sum);
	

	return 0;
}