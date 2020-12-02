#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	
	int n;
	cin>>n;

	int space = n/2;
	int num=1;

	for(int i=1; i<=n; i++){
		int curNum = i;
		int max = i;
		if(i > (n+1)/2){
			curNum = n-i+1;
			max = n-i+1;
		}
		for(int sp = 1; sp <=space; sp++){
			cout<<"\t";
		}
		for(; curNum<=num; curNum++){
			cout<< curNum<<"\t";
		}
		for(int curNum2 =num-1; curNum2 >=max; curNum2--){
			cout<<curNum2<<"\t";
		}
		
		if(i > n/2 ){
			space++;
			num-=2;
		}else{
			space--;
			num+=2;
		}

		cout<<"\n";
	}

	return 0;
}