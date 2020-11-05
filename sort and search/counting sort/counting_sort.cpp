#include <bits/stdc++.h>
using namespace std;

int main(){

	int a[] = {1,2,3,6,3,2,8,15,3};

	int n = sizeof(a)/sizeof(int);

	// size of 'd' array should one more than the highest element in array 'a'
	// or you can take max size of your data type
	int d[16] = {0};

	for(int i=0;i<n;i++){
		++d[a[i]];
	}

	for (int i = 0; i < 16; i++)
	{
		while(d[i]!=0){
			cout<<i<<" ";
			--d[i];
		}
	}

	return 0;
}