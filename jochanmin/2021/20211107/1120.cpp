#include <iostream>
#include <string>
using namespace std;

int main() {
	string a,b;
	cin>>a>>b;
	int max_cnt=0;
	int idx=0;
	int cnt=0;
	for(int i=0;i<=b.size()-a.size();i++){
		cnt=0;
		for(int j=0;j<a.size();j++){
			if(a[j]==b[i+j]) cnt++;
		}
		if(cnt>max_cnt){
			max_cnt=cnt;
		}
	}
	cout<<(a.size()-max_cnt);
	return 0;
}