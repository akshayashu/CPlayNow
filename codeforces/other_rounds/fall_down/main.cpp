#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void print2D(vector<vector<char>> arr, int n, int m){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
    
}

void solve(vector<vector<char>> arr, int n, int m){
    
    vector<int> lastRow(m, n - 1);

    // . is empty
    // * is stone (which shall fall till obstacle or ground)
    // o is obstacle
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < m; j++){
            
            if(arr[i][j] == '*'){ // checking stone

                // started falling
                arr[i][j] = '.';

                // fell down
                arr[lastRow[j]][j] = '*';

                // updating ground idx to the last one
                lastRow[j]--;

            }else if(arr[i][j] == 'o'){ // checking obstacle

                // updating grd idx
                lastRow[j] = i - 1;
            }
            
        }
    }

    print2D(arr, n, m);
    cout << endl;
    
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

        vector<vector<char>> arr(n, vector<char>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                cin >> arr[i][j];
        }
        solve(arr , n, m);
    }

    return 0;
}