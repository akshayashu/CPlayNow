#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void print2D(vector<vector<ll>> arr, int n, int m){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
    
}

void print1D(vector<ll> arr, int n){

    for(int i = 0; i < n; i++){
        
        cout << arr[i];
    }
    
}

ll solve(vector<ll> arr, int n){
    
    ll ans = 0;
    ll lastNum = arr[n-1];

    for(int i = n - 2; i >= 0; i--){
        if(arr[i] >= lastNum){

            while(arr[i] >= lastNum && arr[i] > 0){
                arr[i] /= 2;
                ans++;
            }
        }

        if(arr[i] == lastNum)
            return -1;

        lastNum = arr[i];
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

        vector<ll> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        cout << solve(arr, n) << endl;
    }

    return 0;
}