#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	
	int n;
	cin>>n;

	int a[n];
	int left[n], right[n];

	int curLeft = 0;
	int curRight = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		if(a[i] > curLeft){
			curLeft = a[i]; 
		}
		left[i] = curLeft;
	}


	for (int i = n-1; i >= 0; --i)
	{
		
		if(a[i] > curRight){
			curRight = a[i]; 
		}
		right[i] = curRight;
	}

	int total = 0;

	for(int i = 0; i < n; i++){
		total = total + (min(left[i], right[i]) - a[i]);
	}

	cout<<"Maximum water we can save: "<<total<<endl;

	return 0;
}