#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll solve(vector<string> strs, int n){
    
    unordered_map<string, ll> map;
    ll ans = 0;

    for(string str : strs){

        string temp = str;

        // for string - ab, check aa, ac, a_, .... aj
        for(char ch = 'a'; ch <= 'k'; ch++){
            if(str[0] != ch){
                temp[0] = ch;
                ans += map[temp];
            }
        }

        temp = str;
        
        // for string - ab, check bb, cb, _b, .... jb
        for(char ch = 'a'; ch <= 'k'; ch++){
            if(str[1] != ch){
                temp[1] = ch;
                ans += map[temp];
            }
        }

        map[str]++;
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

        vector<string> strs(n);

        for(int i = 0; i < n; i++){
            cin >> strs[i];
        }

        cout << solve(strs , n) << endl;
    }

    return 0;
}