#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long findFactors(long long n){

    long long count = 0;

    for (long long i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                count++;
 
            else // Otherwise print both
                count += 2;
        }
    }

    return count;
}

void solve(){
    
    long long a, b;
    cin >> a >> b;

    cout << findFactors(abs(a - b)) << endl;

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