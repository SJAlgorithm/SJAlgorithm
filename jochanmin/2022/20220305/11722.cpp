#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,num;
	vector<int> v;
	cin>>n;
	cin>>num;
	v.push_back(-num);
	for(int i=1;i<n;i++){
		cin>>num;
		num=-num;
		if(v.back()<num) v.push_back(num);
		else{
			auto it =lower_bound(v.begin(),v.end(),num);

			*it=num;
		}
		
		
	}
	cout<<v.size();
	return 0;
}