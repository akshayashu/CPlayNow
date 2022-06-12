#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

/*  Logic

a= 10, b = 13

7 ----- 10 ------ 13

10 - 7 --> 3(aa)
13 - 7 --> 6(bb)

2 * aa == bb

*/

void solve(){
    
    unsigned long long int a, b;
    cin >> a >> b;

    if(a == b){
        cout << a << endl;
    }else if(a == 0 || b == 0){
        cout << -1 << endl;
    }else{
        unsigned long long int count = 0;
        unsigned long long int minVal = min(a, b), maxVal = max(a, b);

        while(minVal < maxVal){
            minVal *= 2;
            count++;
        }

        if(minVal >= maxVal){
            minVal /= 2;
            count--;
        }

        unsigned long long int diff = minVal - (maxVal - minVal);

        minVal -= diff;
        maxVal -= diff;

        count += diff;

        minVal *= 2;
        count++;

        count += maxVal;

        cout << count << endl;
    }

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