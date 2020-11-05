#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	
	int a[] = {-2, -43, 23, 6, -1, 7, 2, -8, -14};
	int n = sizeof(a)/sizeof(int);
	int mSum = 0, initial_index = 0, final_index =0;

	//printing sub-arrays
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = i; j < n; ++j)
	// 	{
	// 		cout<<"[";
	// 		for (int k = i; k <= j; ++k)
	// 		{
	// 			cout<<a[k]<<" ";
	// 		}
	// 		cout<<"]\n\n";
	// 	}
	// }


	//printing maximum sub-array
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			int cSum = 0;
			for (int k = i; k <= j; ++k)
			{
				cSum += a[k];
			}
			if(cSum > mSum){
				mSum = cSum;
				initial_index = i;
				final_index = j;
			}
		}
	}

	//printing max sum and sub-array
	cout<<"\n\n[";
	for(int i = initial_index; i<=final_index; i++){
		cout<<a[i]<<" ";
	}
	cout<<"] has the maximum sum = "<<mSum; 


	return 0;
}