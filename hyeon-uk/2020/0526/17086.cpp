#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int, int> pii;

int n, m;
int arr[20][20], mv[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
pii b_shark;
int sz = 2;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				b_shark = { i,j };
				arr[i][j] = 0;
			}
		}
	}
}

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.second == b.second) {
		if (a.first.first == b.first.first) {
			return a.first.second < b.first.second;
		}
		else {
			return a.first.first < b.first.first;
		}
	}
	else {
		return a.second < b.second;
	}
}

bool isIn(int x, int y) {
	return x >= 0 && x < n&&y >= 0 && y < n;
}

vector<pair<pair<int,int>,int>> check_food() {
	queue<pair<pair<int, int>, int>> q;
	vector<pair<pair<int, int>, int>> result;
	bool visited[20][20] = { 0 };

	q.push({ { b_shark.first,b_shark.second }, 0 });
	visited[b_shark.first][b_shark.second] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dst = q.front().second;

		q.pop();

		if (arr[x][y] < sz&&arr[x][y]!=0) {
			result.push_back({ {x,y},dst });
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + mv[i][0];
			int ny = y + mv[i][1];

			if (isIn(nx, ny) && !visited[nx][ny]&& arr[nx][ny] <= sz) {
				q.push({ {nx,ny},dst + 1 });
				visited[nx][ny] = true;
			}
		}
	}
	sort(result.begin(), result.end(), compare);
	return result;
}

void solve() {
	int time = 0;
	int cnt = 0;
	while (true) {
		vector<pair<pair<int,int>,int>> food = check_food();
		if (food.size() == 0) {
			break;
		}
		else {
			int nx = food[0].first.first;
			int ny = food[0].first.second;
			int t = food[0].second;
			time += t;
			b_shark.first = nx;
			b_shark.second = ny;
			arr[nx][ny] = 0;
			cnt++;
			if (cnt == sz) {
				sz++;
				cnt = 0;
			}
		}
	}
	cout << time << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	input();
	solve();
}
