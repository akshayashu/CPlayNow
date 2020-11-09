#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	
	char ch[] = "Hello everyone, let's get this done!";

	char *ptr;

	//strtok is the string separator
	// char *strtok( char *str, char *delimiters)
	ptr = strtok(ch, " ");

	while(ptr != NULL){
		cout<<ptr<<endl;
		ptr = strtok(NULL, " ,"); //NULL signifies - Extract the strings from the original string 
	}

	return 0;
}