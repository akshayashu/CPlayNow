#include <bits/stdc++.h>
#define ll long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

string removeZeros(string str){
	const regex pattern("^0+(?!$)");
 
    // Replaces the matched
    // value with given string
    str = regex_replace(str, pattern, "");
    return str;
}

int main(){

	fastIO
	
	int t;
	cin>>t;

	for(int k = 1; k <= t; k++){
		string str;
		cin>>str;
		string str1 = "", str2 = "";

		if(str.size() == 1 && str[0] != '4'){
			str1 = str;
			str2 = "0";
		}else if(str.size() == 1 && str[0] == '4'){
			str1 = str2= "2";
		}else{
			for(int i = 0; i < str.size(); i++){
				if(str[i] == '4'){
					str1 += "2";
					str2 += "2";
				}else{
					str1 += str[i];
					str2 += "0";
				}
			}
		}
		str2 = removeZeros(str2);
		cout<<"Case #"<<k<<": "<<str1<<" "<<str2<<endl;
	}

	return 0;
}