#include <bits/stdc++.h>
#define ll long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int main(){
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	fastIO
	
	int t;
	cin>>t;

	for(int c = 1; c<= t; c++){
		int row, col;
		cin>>row>>col;

// 		vector< vector<int>> a(row, vector<int>(col));
        int a[row][col];
        priority_queue<pair<int, pair<int, int>>> p;
        map<pair<int, int>, bool> mp;

        ll count = 0;

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				cin >> a[i][j];
				p.push({a[i][j], {i, j}});
			}
		}

		while(!p.empty()){
		    auto t = p.top();
			int val = t.first;
			int x = t.second.first;
			int y = t.second.second;

			p.pop();

			if (val < a[x][y])
			{
				continue;
			}
			if(mp[t.second]){
			    val = a[x][y];
			}

			for(int i=0; i< 4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];

				if(nx >= 0 && nx < row && ny >=0 && ny < col){

					if(val - a[nx][ny] > 1){
						count += val - a[nx][ny]-1;
						a[nx][ny] = val -1;
						mp[{nx, ny}] = true;
						p.push({a[nx][ny], {nx, ny}});
					}
					
				}
			}
		}

		// for(int i=0; i<row; i++){
		//     for(int j=0; j< col; j++){
		//         cout<<a[i][j]<<" ";
		//     }
		//     cout<<endl;
		// }

		cout<<"Case #"<<c<<": "<<count<<endl;
	}

	return 0;
}