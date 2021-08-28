#include <iostream>
#include<queue>
using namespace std;

int n, m;
bool visited[100001] = { 0 };
int main(){
	cin >> n >> m;
	queue<pair<int,int>> q;

	q.push({ n,0 });
	visited[n] = true;
	while (!q.empty()) {
		int now = q.front().first;
		int cost = q.front().second;
		q.pop();
		if (now == m) {
			cout << cost;
			break;
		}
		if (now - 1 >= 0&&!visited[now-1]) {
			q.push({ now - 1,cost + 1 });
			visited[now - 1] = true;
		}
		if (now + 1 <= 100000&&!visited[now+1]) {
			q.push({ now + 1,cost + 1 });
			visited[now + 1] = true;
		}
		if (2 * now <= 100000&&!visited[now*2]) {
			q.push({ 2 * now,cost + 1 });
			visited[2 * now] = true;
		}
	}

	return 0;
}


