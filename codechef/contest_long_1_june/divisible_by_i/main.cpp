#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

void printArray(vector<int> arr, int n){

    for(int num : arr)
        cout << num << " ";
}

void solve(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    int start = 1, end = n;

    for(int i = n - 1; i >= 0; i -= 2){
        arr[i] = end--;
        if(i - 1 >= 0)
            arr[i - 1] = start++;
    }

    printArray(arr, n);
    cout << endl;

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