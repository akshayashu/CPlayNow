#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class TreeNode{
public:
    int val;
    TreeNode *left = NULL, *right = NULL;

    TreeNode(int val){
        this->val = val;
    }
};

void print2D(vector<vector<ll>> arr, int n, int m){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
    
}

void print1D(vector<int> arr, int n){

    for(int i = 0; i < n; i++){
        
        cout << arr[i];
    }
    cout << endl;
}

int root = -1;

unordered_map<int, TreeNode*> makeGraph(vector<int> arr, int n){

    unordered_map<int, TreeNode*> map;

    for(int i = 0; i < n; i++){
        int num = i + 1;
        int par = arr[i];

        // cout << num << " par is " << par << endl;

        if(map.find(par) == map.end()){
            map[par] = new TreeNode(par);
        }

        if(map.find(num) == map.end()){
            map[num] = new TreeNode(num);
        }

        if(num == par){
            root = par;
            continue;
        }

        if(map[par]->right == NULL){
            map[par]->right = map[num];
        }else{
            map[par]->left = map[num];
        }
    }

    return map;
}

vector<vector<int>> ans;

void solve(TreeNode* root, vector<int> arr){
    
    bool included = false;
    if(root == NULL){
        if(arr.size() > 0){
            ans.push_back(arr);
        }
        return;
    }

    arr.push_back(root->val);

    if(root->right != NULL)
        included = true;

    // cout << arr[arr.size() - 1] << endl;
    solve(root->right, arr);

    if(included || root->left == NULL){
        arr = {};
        // cout << arr[arr.size() - 1] << endl;
    }
    solve(root->left, arr);
        
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

        unordered_map<int, TreeNode*> map = makeGraph(arr, n);

        ans = {};
        solve(map[root], {});

        cout << ans.size() << endl;

        for(vector<int> vec : ans){
            cout << vec.size() << endl;

            for(int num : vec){
                cout << num << " ";
            }
            cout <<  endl;
        }
        cout << endl;
    }

    return 0;
}