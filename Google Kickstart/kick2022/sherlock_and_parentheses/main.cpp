#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll getN(ll a, ll b){
    return a > b ? b : a;
}

void solve(){
    
    ll left, right, ans = 0;
    string str;

    cin >> left >> right;

    ll n = getN(left, right);

    ans = (n % mod) * ((n + 1) % mod) / 2;
        
    cout << ans << endl;
    
}

int main(){

    #ifndef ONLINE_JUDGE
 
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
 
    #endif

    clock_t z = clock();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int test = 1; test <= t; test++){
        
        cout << "Case #" << test << ": ";
        solve();
    }

    // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;

    return 0;
}