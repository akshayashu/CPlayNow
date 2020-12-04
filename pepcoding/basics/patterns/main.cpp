#include <bits/stdc++.h>
#define ll long long

using namespace std;

int max(vector<int>& a){
    
    int max = -1e8;
    for(int i=0;i<a.size();i++){
        if(a[i] > max){
            max= a[i];
        }
    }
    
    return max;
}

int min(vector<int>& a){
    
    int min = 1e8;
    for(int i=0;i<a.size();i++){
        if(a[i] < min){
            min = a[i];
        }
    }
    
    return min;
}

int main(){
	
	int n;
	cin>>n;
	vector<int> a(n);

	for(int i=0; i<n;i++){
		cin>>a[i];
	}
	
	cout<<max(a)-min(a);

	return 0;
}