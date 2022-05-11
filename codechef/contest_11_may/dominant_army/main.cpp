#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve(vector<int> arr, int n, int k){

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

        int a, b, c;
        cin >> a >> b >> c;

        if(a > b + c){
            cout << "YES\n";

        }else if(b > a + c ){
            cout << "YES\n";
        }else if(c > b + a){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }

    }

    return 0;
}
