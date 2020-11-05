#include <bits/stdc++.h>
using namespace std;

bool myCompare(pair<string, int> p1, pair<string, int> p2){

	if(p1.second == p2.second){
		return p1.first < p2.first;
	}

	return p1.second > p2.second;

}

int main(){

	int n, min;
	cin>>min>>n;

	pair<string, int> a[n];

	for (int i = 0; i < n; ++i)
	{
		string name;
		int salary;

		cin>>name>>salary;

		a[i].first = name;
		a[i].second = salary;
	}

	sort(a,a+n, myCompare);

	for(int i=0;i<n;i++){

		if(a[i].second > min){
			cout<<a[i].first<<"  "<<a[i].second<<endl;
		}
	}

	return 0;
}