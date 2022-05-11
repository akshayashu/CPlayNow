#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve(vector<int> arr, int n, int k){

    sort(arr.begin(), arr.end());

    int left = 0, right = 0;
    unordered_map<int, int> map;

    int len = 0;
    int ansLeft = -1, ansRight = 0;

    while(right < n){

        if(map[arr[right]] < k){
            
            map[arr[right]]++;
            right++;
            if(right - left > len){
                len = right - left;
                ansLeft = left;
                ansRight = right;
            }
        }else{
            while(map[arr[right]] > k){
                map[arr[left]]--;
                left++;
            }
        }
        cout << left << " " << right << " " << map[arr[right]] << endl;
    }

    if(ansLeft == -1){
        cout << -1 << endl;
    }else{
        cout << ansLeft << " " << ansRight << endl;
    }

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

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        solve(arr, n, k);

    }

    return 0;
}