#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

bool solve(string str){
    
    int sum1 = 0, sum2 = 0;

    for(int i = 0; i <= 2; i++){
        sum1 = sum1 + (str[i] - '0');
        sum2 = sum2 + (str[5-i] - '0');
    }
    
    return sum1 == sum2;

}

int main(){

    #ifndef ONLINE_JUDGE
 
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
 
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){

        string str;
        cin >> str;

        if(solve(str))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}