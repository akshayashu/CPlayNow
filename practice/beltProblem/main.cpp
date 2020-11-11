#include <bits/stdc++.h>
#define ll long long int

using namespace std;


int main(){
	
	ll var1 = 4000005;
	bool var2[var1 + 1];
	
	memset(var2, true, sizeof(var2));
	
	for(ll var3 =2; var3*var3<=var1; var3++){
	    if(var2[var3] == true){
	        for(ll i = var3*var3; i<= var1; ++i){
	            var2[i] = false;
				cout<<"while starting";
	        }
	    }
	}
	
	ll var4 ;
	cin>>var4;
	
	while(var4--){
	    ll var5 = 2;
	    ll var6 = 0;
	    cin>>var6;
	    
	    ll var7[var6];
	    
	    for(ll i=0; i<var6; i++){
	        cin>>var7[i];
	    }
	    
	    unordered_map<ll, ll> var8;
	    
	    for(ll i=0; i< var6; i++){
	        if(var8.find(var7[i]) == var8.end()){
	            
	            while(var2[var5] == 0){
	                var5++;
	            }
                var8[var7[i]] = var5;
                var5++;
	        }
	    }
	    
	    for(ll i=0; i<var6; i++){
	        cout << var8[var7[i]]<< " ";
	    }
	    
	    cout<<"\n";
	    
	}
	
	return 0;
}