#include <iostream>
#include<algorithm>
using namespace std;

int team[6][3] = { 0 };//매순간 상태를 저장하는 배열
int arr[4][6][3];//입력받은거 저장하는 배열
int result[4] = { 0 };//결과 저장 배열

//매칭되는 경우를 모두 저장
pair<int, int> game[15] = { 
	{0,1},{0,2},{0,3},{0,4},{0,5},{1,2},{1,3},{1,4},{1,5},{2,3},{2,4},{2,5},{3,4},{3,5},{4,5} 
};

void dfs(int cnt) {	

	//6명이서 토너먼트하면 총 15게임을 함
	if (cnt == 15) {
		//비교
		for (int k = 0; k < 4; k++) {
			bool flag = true;
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 3; j++) {
					if (team[i][j] != arr[k][i][j]) {
						flag = false;
						break;
					}
				}
				if (!flag) break;
			}
			if (flag) {
				result[k] = 1;
			}
		}
		return;
	}

	//i팀과 j팀의 경기
	int i = game[cnt].first;
	int j = game[cnt].second;

	//승
	team[i][0]++;
	team[j][2]++;
	dfs(cnt + 1);
	team[i][0]--;
	team[j][2]--;

	//무승부
	team[i][1]++;
	team[j][1]++;
	dfs(cnt + 1);
	team[i][1]--;
	team[j][1]--;

	//패
	team[i][2]++;
	team[j][0]++;
	dfs(cnt + 1);
	team[i][2]--;
	team[j][0]--;
		
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> arr[k][i][j];
			}
		}
	}
	dfs(0);
	for (int ret:result) {
		cout << ret << " ";
	}
	return 0;
}