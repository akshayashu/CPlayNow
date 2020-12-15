#include<bits/stdc++.h>
using namespace std;

int addition(int n1, int n2, int b){
    int i=0, final = 0, carry = 0, power = 1;
    
    while(n1!=0 || n2!=0 || carry !=0){
        int r1 = n1%10;
        int r2 = n2%10;
        
        int sum =r1+r2+carry;
        
        n1/=10;
        n2/=10;
        
        int rem = sum%b;
        carry = sum/b;
        
        final += rem * power;
        power *= 10;
    }
    return final;
}


int multiply(int n, int q, int power, int b){
    int ans = 0, carry = 0;
    cout<<"\n\n";
    while(n!=0 || carry!=0){
        int m2 = n%10;
        int res = m2*q+carry;
        cout<<m2<<" x "<<q<<" + "<<carry<< " = "<<res<<endl;
        
        n/=10;
        
        int rem = res%b;
        carry = res/b;
        
        ans += rem*power;
    	cout<<ans<<"\n";
        power *=10;
    }
    return ans;
}

int anyBaseSub(int n2, int n1, int b){
    int i=0, ans = 0, power = 1, power1 = 1, res = 0 ;
    int a1=0,a2=0;
    
    while(n1!=0 ){
        
        int r1 = n1%10;
        
        a2 = multiply(n2, r1, power1, b);
        res = addition(a1,a2, b);
        a1=res;

        
        n1 /=10;
        power1*=10;
    }
    return res;
}

int main(){
    
    int n1, n2, b;
    cin>>b>>n1>>n2;
    
    cout<<anyBaseSub(n1, n2, b);
    
    return 0;
    
}