#include <bits/stdc++.h>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);

	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int i = 0; i < n; i++){
		cin>>b[i];
	}	

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int count = 0, j = n-1;
	for(int i = n-1; i >= 0; i--){
		if(a[i] <= b[j]){
			count++;
			j--;
		}
	}	

	cout<<count;

	return 0;			
}
