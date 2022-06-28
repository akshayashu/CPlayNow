#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

void solve(){
    
    int n, q, ans = 0;
    cin >> n >> q;

    string str;
    cin >> str;

    vector<vector<int>> dp(n + 1, vector<int>(26));
    
    for(int i = 0; i < n; i++){
        dp[i+1] = dp[i];
        dp[i+1][str[i] - 'A']++;
    }

    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;

        int odd = 0;
        --l;

        for(int i = 0; i < 26; i++){
            odd += (dp[r][i] - dp[l][i]) & 1;
            if(odd > 1) break;
        }

        if(odd <= 1){
            ans++;
        }
    }

    cout << ans << endl;
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

    for(int test = 1; test <= t; test++){
        
        cout << "Case #" << test << ": ";
        solve();
    }

    // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;

    return 0;
}