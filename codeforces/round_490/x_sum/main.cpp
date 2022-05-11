#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll solve(vector<vector<int>> arr, int n, int m){
    
    int diag = n + m - 1;
    int antiDiag = n + m - 1;

    int ans = 0;

    unordered_map<int, int> mapDiag;
    unordered_map<int, int> mapAntiDiag;

    // diagonal
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mapDiag[i + j] += arr[i][j];
            mapAntiDiag[n - 1 + (i - j)] += arr[i][j];
        }
    }

    // logic
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int cur = mapDiag[i + j] + mapAntiDiag[n - 1 + (i - j)] - arr[i][j];
            ans = max(ans, cur);
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

        int n, m;
        cin >> n >> m;

        vector<vector<int>> arr(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> arr[i][j];
            }
        }


        cout << solve(arr, n, m) << endl;
    }

    return 0;
}