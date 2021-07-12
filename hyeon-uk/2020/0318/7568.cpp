#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
using namespace std;

int main() {
	int n;
	vector<pair<int, int>> arr;
	int x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arr.push_back(make_pair(x,y));
	}
	int cnt;
	for (vector<pair<int,int>>::size_type i=0; i < arr.size(); i++) {
		cnt = 0;
		for (vector<pair<int, int>>::size_type j = 0; j < arr.size(); j++) {
			if (arr.at(i).first < arr.at(j).first&&arr.at(i).second < arr.at(j).second) cnt++;
		}
		cout << cnt+1 << " ";
	}
}
