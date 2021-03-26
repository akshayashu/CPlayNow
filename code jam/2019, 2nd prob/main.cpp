#include <bits/stdc++.h>
#define ll long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int main(){

	fastIO
	
	int t;
	cin>>t;

	for(int k = 1; k<= t; k++){
		int n;
		cin>>n;

		string oppPath, myPath = "";
		cin>>oppPath;

		for(int i = 0; i < oppPath.size(); i++){
			if(oppPath[i] == 'S'){
				myPath += "E";
			}else{
				myPath += "S";
			}
		}

		cout<<"Case #"<<k<<" :"<<myPath<<endl;

	}

	return 0;
}