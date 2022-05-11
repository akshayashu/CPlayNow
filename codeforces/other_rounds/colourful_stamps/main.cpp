#include <bits/stdc++.h>
using namespace std;


string solve(string str, int n){

    char prev = 'N';
    bool paired = false;

    for(int i = 0; i < n; i++){
        
        if(str[i] == 'W'){

            if((prev == 'R' || prev == 'B') && paired == false){
                return "NO";
            }

            paired = false;

        }else if(str[i] == 'R'){

            // alternative state
            if(prev == 'B'){
                paired = true;
            }else if(prev == 'W'){
                paired = false;
            }
        }else{
            // alternative state
            if(prev == 'R'){
                paired = true;
            }else if(prev == 'W'){
                paired = false;
            }
        }

        prev = str[i];
    }
    
    return ( (prev == 'B' || prev == 'R') && !paired ) ? "NO" : "YES";
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
        cin >> n;

        string str;
        cin >> str;

        cout << solve(str, n) << endl;
    }

    return 0;
}