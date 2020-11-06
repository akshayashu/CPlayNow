#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int a[n];

		for(int i=0; i<n;i++){
			cin>>a[i];
		}

		sort(a, a+n, greater<int>());
 
		if(n==1){
			cout<<a[0]<<endl;
		}else{

			int first_gas =0, second_gas = 0, last_gas = 0;
			int total_time=0;
			for(int i=0; i<n; i++){
				int mini_num;
				if (first_gas == second_gas)
				{
					total_time += first_gas;
					first_gas = a[i];
					i++;
					if(i<n){
						second_gas = a[i];
					} else{
						second_gas = 0;
					}
					last_gas = max(first_gas, second_gas);
				} 
				else if(first_gas < second_gas){
					mini_num = first_gas;
					first_gas = a[i];
					second_gas -=mini_num;
					total_time += mini_num;
					last_gas = max(first_gas, second_gas);
				} 
				else{
					mini_num = second_gas;
					second_gas = a[i];
					first_gas -=mini_num;
					total_time += mini_num;
					last_gas = max(first_gas, second_gas);
				}

			}

			cout<<total_time+ last_gas<<endl;

		}

	}

	return 0;
}

// PROBLEM STATEMENT


// Example Input
// 3
// 3
// 2 2 2
// 3
// 1 2 3
// 4
// 2 3 4 5
// Example Output
// 4
// 3
// 7
// Explanation
// Example case 1: Place the first two dishes on the burners, wait for two minutes, remove both dishes and 
// prepare the last one on one burner.

// Example case 2: Place the first and third dish on the burners. 
// When the first dish is prepared, remove it and put the second dish on the same burner.

// Example case 3: Place the third and fourth dish on the burners. 
// When the third dish is prepared, remove it and put the second dish on the same burner. 
// Similarly, replace the fourth dish (when it is prepared) by the first dish on the other burner.