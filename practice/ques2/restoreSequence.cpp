#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool prime[400001];
int a[400001];

void SieveOfEratosthenes() 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true.  
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=400000; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=400000; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers
    int p=2, i=0;
    while(p < 400001){
    	if (prime[p]) {
    		a[i] = p;
    		i++;
    	}
    	p++;
    } 
    
       
} 

void solve(int n, int b[]){

	int c[n];
	
    for (int i=0; i<n; i++){
    	
		c[i] = a[b[i]-1];

    } 

    for (int i = 0; i < n; ++i)
    {
    	cout<<c[i]<<" ";
    }
    cout<<"\n";
}

int main(){
	
	int t;
	cin>>t;
	SieveOfEratosthenes();

	while(t--){
		int n;
		cin>>n;
		int b[n];

		for (int i = 0; i < n; ++i)
		{
			cin>>b[i];
		}

		solve(n, b);
	}

	return 0;
}