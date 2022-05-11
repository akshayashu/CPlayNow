#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll solve(vector<string> strs, int n, int m){

    int ans = INT_MAX;

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            
            int cur = 0;
            
            for(int idx = 0; idx < m; idx++){
                cur += abs(strs[i][idx] - strs[j][idx]);
            }
            
            ans = min(ans, cur);
        }
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

        int n, q;
        cin >> n >> q;

        vector<string> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        cout << solve(arr, n, q) << endl;

    }

    return 0;
}