#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<char> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	v.erase(unique(v.begin(), v.end()),v.end());
	cout << v.size() + 1;
}
