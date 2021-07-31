#include <iostream>
#include<algorithm>
using namespace std;

int road[1000001] = { 0 };
int n;
long long min_cost = 1000000001;
long long result = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> road[i];
	}
	for (int i = 0; i < n; i++) {
		long long city;
		cin >> city;

		min_cost = min(min_cost, city);
		result += min_cost * road[i];
	}
	cout << result;
	return 0;
}
