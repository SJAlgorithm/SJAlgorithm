#include <iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string str;
	cin>>str;
	vector<int> v;
	int arr[]={3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1};
	for(int i=0;i<str.size();i++){
		v.push_back(arr[str[i]-'A']);
	}
	int sum=0;
	for(int i=0;i<v.size();i++){
		sum+=v[i];
		sum%=10;
	}
	if(sum%2==0){
		cout<<"You're the winner?";
	}else{
		cout<<"I'm a winner!";
	}
	return 0;
}