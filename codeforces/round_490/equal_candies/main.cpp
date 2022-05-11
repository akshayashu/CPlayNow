#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll solve(vector<int> arr, int n){
    
    int minValue = INT_MAX;
    ll ans = 0;

    for(int num : arr){
        minValue = min(minValue, num);
    }

    for(int num : arr){
        ans = (ans + (num - minValue)) % mod;
    }

    return ans;

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

        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }


        cout << solve(arr, n) << endl;
    }

    return 0;
}