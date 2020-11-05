#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	int n;
	cin>>n;

	int a[n], cumSum[n+1]={0};

	cin>>a[0];
	cumSum[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		cin>>a[i];
		cumSum[i] = cumSum[i-1] + a[i];
	}
	int mSum = 0, initial_index = -1, final_index =-1;


	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int cSum = 0;
			
			cSum = cumSum[j] - cumSum[i-1];
			if(cSum > mSum){
				mSum = cSum;
				initial_index = i;
				final_index = j;
			}
		}
	}

	cout<<"\n\n[";
	for(int i = initial_index; i<=final_index; i++){
		cout<<a[i]<<" ";
	}
	cout<<"] has the maximum sum = "<<mSum; 



	return 0;
}