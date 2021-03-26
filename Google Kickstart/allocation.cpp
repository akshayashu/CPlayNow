#include <bits/stdc++.h>
#define ll long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int main(){

	fastIO;
	
	int t;
	cin>>t;

	for(int k = 1; k <= t; k++){
		int n, b;
		cin>>n>>b;

		vector<int> a;
		for(int i = 0; i < n; i++){
			int num;
			cin>>num;
			a.push_back(num);
		}
		sort(a.begin(), a.end());

		int i = 0, count = 0;
		while(b >= a[i] && i < n){
			b -= a[i];
			count++;
			i++;
		}
		cout<<"Case #"<<k<<": "<<count<<endl;
	}

	return 0;
}