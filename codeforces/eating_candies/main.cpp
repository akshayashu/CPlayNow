#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll solve(vector<int> arr, int n){
    
    ll ans = 0;
    vector<int> left(n), right(n);

    left[0] = arr[0];
    right[n - 1] = left[n - 1];

    // left
    for(int i = 1; i < n; i++){
        left[i] = arr[i] + left[i - 1];
    }

    // right
    for(int i = n - 2; i >= 0; i--){
        right[i] = arr[i] + right[i + 1];
    }

    int i = 0, j = n - 1;
    int leftSum = 0, rightSum = 0;
    int count = 0;

    while(i <= j){
        if(leftSum == rightSum){
            ans = count;
        }

        if(leftSum <= rightSum ){
            leftSum += arr[i];
            i++;
        }else{
            rightSum += arr[j];
            j--;
        }
        
        count++;
    }
    if(leftSum == rightSum){
        ans = count;
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

        cout << solve(arr , n) << endl;
    }

    return 0;
}