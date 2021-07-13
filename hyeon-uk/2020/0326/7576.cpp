#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

queue<pair<int, pair<int, int>>> q;
int v[1000][1000];
bool visited[1000][1000] = { 0 };
int m, n;
int cnt = 0;
int mv[4][2]={
	{1,0},{-1,0},{0,1},{0,-1}
};

bool isIn(int nn, int mm) {
	return (nn >= 0 && nn < n&&mm >= 0 && mm < m);
}

void bfs() {
	if (cnt == 0) {
		cout << "0\n";
		return;
	}
	int day;
	while (!q.empty()) {
		int nown = q.front().second.first;
		int nowm = q.front().second.second;
		day = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextn = nown + mv[i][0];
			int nextm = nowm + mv[i][1];

			if (isIn(nextn, nextm)&&!visited[nextn][nextm]&&v[nextn][nextm]==0) {
				v[nextn][nextm] = 1;
				visited[nextn][nextm] = true;
				q.push({ day + 1,{ nextn,nextm } });
				cnt--;
			}
		}
	}

	if (cnt == 0) {
		cout << day << "\n";
		return;
	}
	else {
		cout << "-1\n";
		return;
	}

}


int main() {
	cin >> m >> n;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> v[j][k];
				if (v[j][k] == 0) cnt++;
				if (v[j][k] == 1) {
					q.push({ 0, { j,k } });
					visited[j][k] = true;
				}
			}
		}

	bfs();

}