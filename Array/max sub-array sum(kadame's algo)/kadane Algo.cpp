#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	
	int a[] = {-2, -43, 23, 6, -1, 7, 2, -8, -14};
	int n = sizeof(a)/sizeof(int);
	int mSum = 0, cSum = 0, initial_index = 0, final_index =0;


	//kadane's algorithm for max sum of sub-array
	for (int i = 0; i < n; ++i)
	{
		cSum = cSum+a[i];
		if(cSum < 0){
			cSum = 0;
		}
		mSum = max(cSum, mSum);
	}

	cout<<mSum;

	return 0;
}