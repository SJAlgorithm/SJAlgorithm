#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, k;
int check[300001] = { 0 };
vector<int> back;
vector<pair<int, int>> V;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		V.push_back({ m,v});
	}
	for (int i = 0; i < k; i++) {
		int data;
		cin >> data;
		back.push_back(data);
	}
	sort(V.begin(), V.end(), compare);
	sort(back.begin(), back.end());

	long long sum = 0;
	int index = 0;
	priority_queue<int> pq;
	for (int i = 0; i < k; i++) {
		while (index < n&&back[i] >= V[index].first) {
			pq.push(V[index++].second);
		}

		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum;
}
