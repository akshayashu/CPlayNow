#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

void solve(){
    
    vector<bool> count(26, false);

    int n;
    string str1, str2;
    cin >> n >> str1 >> str2;

    for(int i = 0; i < str1.size(); i++){

        if(str1[i] != str2[i]){
            int idx = str2[i] - 'a';

            count[idx] = true;
        }
    }

    int ans = 0;
    for(bool b : count)
        if(b)
            ans++;

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

    while(t--){
        solve();
    }

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;

    return 0;
}