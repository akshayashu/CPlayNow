#include <bits/stdc++.h>
#define MAX_INT 10000
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a[] = {1,3,4,2,7,8,9,10,11,12,4,3,2,1};

    int n = sizeof(a)/sizeof(int);

    for (int i = 0; i < n; i+=2)
    {
    	//check for the left element
    	if(i>0 && a[i-1]> a[i]){
    		swap(a[i], a[i-1]);
    	}

    	//check for the right element
    	if(i<n-1 && a[i] < a[i+1]){
    		swap(a[i], a[i+1]);
    	}
    }

    for(int i=0;i<n;i++){
    	cout<<a[i]<<" ";
    }

	return 0;
}