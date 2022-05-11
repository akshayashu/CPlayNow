#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

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

        ll n;
        cin >> n;

        vector<ll> arr1(n);
        vector<ll> arr2(n);

        for(int i = 0; i < n; i++){
            cin >> arr1[i];
        }

        map<pair<int, int>, int> map;
        ll ans = 0;

        for(int i = 0; i < n; i++){
            cin >> arr2[i];
            
        }

        for(int i = 0; i < n; i++){
            ans = ans + map[{arr1[i], arr2[i]}];
            map[{arr2[i], arr1[i]}]++;
        }

        cout << ans << endl;
        // solve(arr1, arr2, n, map);
    }

    return 0;
}
