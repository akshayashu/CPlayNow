#include <bits/stdc++.h>
#define ll long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

int main(){

	fastIO;
	
	int t;
	cin>>t;

	for(int c = 1; c <= t; c++){

		int row ,col;
		cin >> row >> col;

		int a[row][col];

		int left[row][col];
		int right[row][col];
		int up[row][col];
		int down[row][col];

		for(int i =0; i< row; i++){
			for(int j=0; j<col; j++){
				cin>> a[i][j];
			}
		}
		//left side
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				left[i][j] = a[i][j];

				if( j && a[i][j]){
					left[i][j] += left[i][j-1];
				}
			}
		}

		//right side
		for(int i=0; i<row; i++){
			for(int j=col-1; j>=0; j--){
				right[i][j] = a[i][j];

				if( j < col-1 && a[i][j]){
					right[i][j] += right[i][j+1];
				}
			}
		}

		//up side
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				up[i][j] = a[i][j];

				if( i && a[i][j]){
					up[i][j] += up[i-1][j];
				}
			}
		}

		//down side
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				down[i][j] = a[i][j];

				if( i < row-1 && a[i][j]){
					down[i][j] += down[i+1][j];
				}
			}
		}

		ll ans = 0;

		for(int i = 0; i< row; i++){
			for(int j=0; j< col; j++){

				if(up[i][j] > 1){
					if(left[i][j] > 2){
						ans += min(up[i][j], left[i][j]/2)-1;
					}
					if(right[i][j] > 2){
						ans += min(up[i][j], right[i][j]/2)-1;
					}
				}
				if(down[i][j] > 1){
					if(left[i][j] > 2){
						ans += min(down[i][j], left[i][j]/2)-1;
					}
					if(right[i][j] > 2){
						ans += min(down[i][j], right[i][j]/2)-1;
					}
				}
				if(left[i][j] > 1){
					if(up[i][j] > 2){
						ans += min(up[i][j]/2, left[i][j])-1;
					}
					if(down[i][j] > 2){
						ans += min(down[i][j]/2, left[i][j]/2)-1;
					}
				}
				if(right[i][j] > 1){
					if(up[i][j] > 2){
						ans += min(up[i][j]/2, right[i][j])-1;
					}
					if(down[i][j] > 2){
						ans += min(down[i][j]/2, right[i][j]/2)-1;
					}
				}
			}
		}

		cout<<"Case #"<<c<<": "<<ans<<endl;
	}

	return 0;
}