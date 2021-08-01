#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maze[101][101] = { 0 };
int mv[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };

bool isIn(int x, int y) {
	return x >= 0 && x <= 100 && y >= 0 && y <= 100;
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		vector<pair<int, int>> point;
		point.push_back({ y,x });
		maze[y][x] = 1;
		if (isIn(y + mv[d][0], x + mv[d][1])) {
			point.push_back({ y + mv[d][0],x + mv[d][1] });
			maze[y + mv[d][0]][x + mv[d][1]] = 1;
		}
		for (int j = 1; j <= g; j++) {
			int psize = point.size();
			pair<int, int> endPoint = point[psize - 1];
			
			for (int k = psize - 2; k >= 0; k--) {
				int dx = endPoint.first - point[k].first;
				int dy = endPoint.second - point[k].second;
				if (!isIn(endPoint.first-dy, endPoint.second+dx)) continue;

				maze[endPoint.first - dy][endPoint.second+ dx] = 1;
				point.push_back({ endPoint.first - dy,endPoint.second + dx });
			}
		}

	}
	int cnt = 0;
	for (int i = 0; i <=100; i++) {
		for (int j = 0; j <=100; j++) {
			if (maze[i][j] == 1 && maze[i + 1][j] == 1 && maze[i][j + 1] == 1 && maze[i + 1][j + 1] == 1) cnt++;
		}
	}
	cout << cnt << "\n";
}
