#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	
	int m,n, key;
	cin>>m>>n>>key;

	int a[m][n];
	bool flag = false, search = true;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>a[i][j];
		}
	}

	int smallest = a[0][0], largest = a[m - 1][n - 1]; 
    if (key < smallest || key > largest) {
        flag = false;
        search = false;
    }

	int i = 0, j = n-1;
    if(search){
	    while(i < m && j >= 0){
	    	if(a[i][j] == key){
	    		flag = true;
	    		break;
	    	} 
	    	else if( a[i][j] < key){
	    		i++;
	    	}
	    	else{
	    		j--;
	    	}
	    }
	}

    if(flag){
    	cout<<"Found the element at index : Matrix["<<i<<"]["<<j<<"]"<<endl;
    } else{
    	cout<<"No such element found!"<<endl;
    }

	return 0;
}