#include <iostream>
#include <math.h>
#define ll long long
using namespace std;

int countDigits(int n){
    int count=0;
    while(n>0){
        n=n/10;
        count++;
    }
    return count;
}

int main(int argc, char **argv){
    int n,r;
    cin >> n>>r;
    int len=countDigits(n);
    r= r%len;
    if(r<0) r=(r+len)%len;
    
    int mul=1 , div=1;
    for(int i=1; i<=len;i++){
        if (i<=r) div=div*10;
        else mul=mul*10;
    }
    int A = n%div;
    int B = n/div;
    cout<<(A*mul + B);
    
    return 0;
}
