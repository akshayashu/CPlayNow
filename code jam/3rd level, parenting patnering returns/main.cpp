#include <bits/stdc++.h>
#define ll long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

class TaskTime
{
public:
	int idx;
	int start;
	int end;

	TaskTime(int i, int a, int b){
		idx = i;
		start = a;
		end = b;
	}
	int getStart(){
		return start;
	}
	int getEnd(){
		return end;
	}
};

bool compareTask(TaskTime t1, TaskTime t2){
	return t1.start < t2.start;
}

int main(){

	fastIO;
	
	int t, caseNo = 1;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<TaskTime> a;
		for(int i=0; i<n; i++){
			int num1, num2;
			cin>>num1;
			cin>>num2;
			TaskTime task = TaskTime(i, num1, num2);
			a.push_back(task);
		}

		sort(a.begin(), a.end(), compareTask);
		bool final = true;

		vector<string> str(n);
		str[a[0].idx] = "C";
		str[a[1].idx] = "J";
		TaskTime camTask = a[0];
		TaskTime jamTask = a[1];

		

		for(int i = 2; i< n; i++){
			if(camTask.end <= a[i].start){
				camTask.start = a[i].start;
				camTask.end = a[i].end;
				str[a[i].idx] = "C";
			}else if(jamTask.end <= a[i].start){
				jamTask.start = a[i].start;
				jamTask.end = a[i].end;
				str[a[i].idx] = "J";
			}else{
				final = false;
				break;
			}
		}

		cout<<"Case #"<<caseNo++<<": ";
		if(final){
			for(int i=0; i<n; i++){
				cout<<str[i];
			}
			cout<<endl;
		}else{
			cout<<"IMPOSSIBLE\n";
		}

	}

	return 0;
}