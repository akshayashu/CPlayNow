#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    
    for(int x=0; x<t; x++){
        int n;
        cin>>n;
		vector<vector<int>> vec(200, vector<int> (100, 0));

        int a[n][n];
        for(int i=0; i<n; i++){
            for(int j = 0; j<n; j++){
                cin>>a[i][j];
                vec[i][a[i][j]-1] += 1;
                vec[j+n][a[i][j]-1] +=1;
            }
        }

        int k = 0, r = 0, c = 0;
    
	    //diagonal sum
	    for(int i=0; i<n; i++){
	        k = k + a[i][i];
	    }
	    
	    for(int i=0; i<n; i++){
	    	bool flag1 = false, flag2 = false;
	        for(int j = 0; j<n; j++){
	            if(vec[i][j] > 1){
	                flag1 = true;
	            }
	            if(vec[i+3][j] > 1){
	            	flag2 = true;
	            }
	        }
	        if(flag1){
	        	r++;
	        }
	        if(flag2){
	        	c++;
	        }
	    }
	    
	   
	    cout<<"Case #"<<x+1<<": "<<k<<" "<<r<<" "<<c<<endl;
    }
    return 0;
}
