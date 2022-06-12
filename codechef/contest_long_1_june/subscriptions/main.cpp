#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

void solve(){
    
    int n, x;
    cin >> n >> x;

    long long ans = 0;

    int quo = n / 6;
    int rem = n % 6;

    cout << x * quo + (rem != 0 ? x : 0) << endl;
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

    while(t--){
        solve();
    }

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;

    return 0;
}