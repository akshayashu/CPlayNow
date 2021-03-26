#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, num = 1;
    cin>>t;
    
    while(t--){
        string str;
        cin>>str;

        int openedBracket = 0;
        cout<<"Case #"<<num++<<": "; 

        for(int i=0; i < str.size(); i++){
        	int cur = str[i] - '0';

        	if(cur >+ openedBracket){
        		cur -= openedBracket;
        		while(cur--){
        			cout<<"(";
        			openedBracket++;
        		}
        	}else{
        		cur = openedBracket - cur;
        		while(cur--){
        			cout<<")";
        			openedBracket--;
        		}
        	}
        	
        	cout<<str[i];
        }
        while(openedBracket--){
			cout<<")";
        }
        cout<<endl;
    }
    
    
    return 0;
}