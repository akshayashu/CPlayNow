#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m;

int find(int a[][], int i, int j){

			if(a[x+1][y] == 1){
				x++;
				a[x][y] = 0;
				curCount++;
			}
			if(a[x][y+1] == 1){
				x++;
				y++;
				a[x][y] = 0;
				curCount++;
			}
			if(a[x-1][y] == 1){
				x++;
				y++;
				a[x][y] = 0;
				curCount++;
			}
			if(a[x][y-1] == 1){
				x++;
				y++;
				a[x][y] = 0;
				curCount++;
			}
		
}

int solve(int a[][]){

	int maxCount = 0, curCount = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(a[i][j] == 1){
				curCount = find(a, i, j);
			}
		}
	}

}

int main(){
	
	cin>>m>>n;

	int a[n][m];
	bool flag = false;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; i < m; ++j)
		{
			cin>>a[i][j];
			if(a[i][j] == 1){
				flag = true;
			}
		}
	}

	if(flag){
		cout<< solve(a);
	} else {
		cout<< 0;
	}

	return 0;
}