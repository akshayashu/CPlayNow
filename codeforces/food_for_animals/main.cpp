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

void solve(ll a, ll b,ll c, ll x,ll y){
    
    if(a > x){
        x = 0;
        a -= x;
    }else{
        x -= a;
        a = 0;
    }

    if(b > y){
        y = 0;
        b -= y;
    }else{
        y -= b;
        b = 0;
    }

    if(x == 0 && y == 0){
        cout << "YES\n";
    }else if(x + y <= c){
        cout << "YES\n";
    }else{
        cout << "NO\n";
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

        ll a,b,c,x,y;
        cin >> a >> b >> c >> x >> y;

       
        solve(a,b,c,x,y);
    }

    return 0;
}