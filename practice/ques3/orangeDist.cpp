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


// Problem :

// Sample Input 1:
// 5 140
// 50
// 20
// 80
// 10
// 5

// Sample Output 1:
// Thank you, your order for 140 oranges are accepted
// 50  50  0
// 20  20  0
// 80  70  10
// 10  0  10
// 5    0    5


// Sample Input 2:
// 4 260
// 80
// 50
// 30
// 70

// Sample Output 2:
// Sorry, we can only supply 229 oranges
// 80 80 0
// 50 50 0
// 30 30 0
// 70 69 1