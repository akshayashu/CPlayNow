#include <bits/stdc++.h>

using namespace std;

bool check(string search, vector<string> dict){
	for(int i=0; i < dict.size(); i++){
		if(search == dict[i]){
			return true;
		}
	}
	return false;
}

bool backTrack(string str, vector<string> dict, int sh, int lg){
	
	if(str.size() == 0){
		return true;
	}

	bool flag = false;
	for(int i=0; i < str.size(); i++){

		for(int j = sh; j <= lg; j++){
			if(j <= str.size()){
				string search = str.substr(i, j);
				string rest = str.substr(j);

				if( check(search, dict)){
					flag = backTrack(rest, dict, sh, lg);
					return flag;
				}else{
					if(j == lg){
						return false;
					}
				}
			}
		}
	}

	return flag;
}

bool findLength(vector<string> dict, int n, string str){
	int sh = 100, lg = 0;
	for(int i=0; i<n; i++){
		if(dict[i].size() > lg){
			lg = dict[i].size();
		}
		if(dict[i].size() < sh){
			sh = dict[i].size();
		}
	}

	return backTrack(str, dict, sh, lg);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin>>n;

		vector<string> dict(n);
		
		for(int i = 0; i<n; i++){
			cin>>dict[i];
		}
		string str;
		cin>>str;

		cout<<findLength(dict, n, str)<<endl;
	}

	return 0;
}
