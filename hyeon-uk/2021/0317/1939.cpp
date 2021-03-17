#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int n, m,st,dest;
int Max=0;
vector<pair<int,int>> edge[100001];
bool visited[100001];
void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
		Max = max(Max, c);
	}
	cin >> st >> dest;
}

bool bfs(int weight) {
	queue <int> q;

	q.push(st);
	visited[st] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		//도착할 수 있으면 true 리턴
		if (now == dest) {
			return true;
		}

		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i].first;
			int maxWeight = edge[now][i].second;

			//현재 중량을 들고 도로를 통과 가능하다면 push
			if (!visited[next] && weight <= maxWeight) {
				visited[next] = true;
				q.push(next);
			}
		}
	}

	//못가면 false
	return false;
}

void solve() {
	int left = 0;
	int right = Max;


	while (left <= right) {
		memset(visited, false, sizeof(visited));
		int middle = (left + right) / 2;
	
		//성공하면 무게를 좀 더 올려도 되므로 left업데이트
		if (bfs(middle)) {
			left = middle+1;
		}
		//실패하면 무게를 줄여야하므로 right업데이트
		else {
			right = middle - 1;
		}
	}
	cout << right << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	input();
	solve();
}