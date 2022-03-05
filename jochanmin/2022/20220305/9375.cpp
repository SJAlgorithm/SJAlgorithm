#include <iostream>
#include <map>
#include<string>
using namespace std;
map<string, int> clothes;
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		clothes.clear();
		string name,type;
		for(int i=0;i<n;i++){
			cin>>name>>type;
			clothes[type]++;
		}
		int cal=1;
		for(auto it=clothes.begin();it!=clothes.end();it++){
			cal*=(it->second+1);
		}
		cout<<cal-1<<'\n';
	}
	return 0;
}