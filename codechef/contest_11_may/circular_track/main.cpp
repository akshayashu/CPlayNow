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

        ll a, b, n;
        cin >> a >> b >> n;

        ll diff = abs(a - b);

        if(diff <= n/2){
            cout << diff << endl;
        }else{
            cout << n - diff << endl;
        }

        

    }

    return 0;
}
