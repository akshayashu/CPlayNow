#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void print2D(vector<vector<ll>> arr, int n, int m){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
    
}

void print1D(vector<ll> arr, int n){

    for(int i = 0; i < n; i++){
        
        cout << arr[i];
    }
    
}

ll solve(string str, int n){
    
    if(n == 1){
        return 1;
    }

    ll ans = 1, consQues = 0;
    
    lastChar = str[n- 1];
    consQues = (str[n - 1] == '?') ? 1 : 0;

    for(int i = n - 2; i >= 0; i++){

        if(str[i] == lastChar && lastChar == '?'){
            consQues
        }

        switch(lastChar){
            case '0': 
                if(str[i] == '0'){
                    consQues = 0;
                }else if(str[i] == '?'){
                    consQues++;
                    ans++;
                }else{
                    consQues = 0;
                    // nothing
                }
                break;

            case '1':
                if(str[i] == '0'){
                    consQues = 0;
                    ans++;
                }else if(str[i] == '?'){
                    consQues++;
                    ans++;
                }else{
                    consQues = 0;
                    // nothing
                }
                break;

            case '?':
                if(str[i] == '0'){
                    consQues = 0;
                    ans++;
                }else if(str[i] == '?'){
                    consQues++;
                    ans++;
                }else{
                    consQues = 0;
                    // nothing
                }
                consQues++;
                break;  

        }
    }

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

        int n;
        string str;

        cin >> str;
        n = str.size();

        
        cout << solve(str, n) << endl;
    }

    return 0;
}