#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int arrx[50000];
int arry[50000];
bool result = false;

void dfs(int cnt, vector<pair<int, int>> l) {
	//정답이 나왔으면 dfs수행 필요x
	if (result) {
		return;
	}

	//선이 3개 이상이면 리턴
	if (l.size() > 3) {
		return;
	}

	//n개를 다 탐색했는데도 3개 이하이면 정답
	if (cnt == n) {
		result = true;
		return;
	}

	//처음 넣는것은 x축에 대한 dfs, y축에 대한dfs실행
	if (cnt == 0) {
		l.push_back({ arrx[0],-1 });
		dfs(cnt + 1, l);
		l.pop_back();
		l.push_back({ -1,arry[0] });
		dfs(cnt + 1, l);
	}
	else {
		bool flag = false;

		//현재 존재하는 선을 돌며
		for (int i = 0; i < l.size(); i++) {
			//x좌표가 같으면 선을 추가할 필요 없이 다음 cnt dfs실행
			if (l[i].first == arrx[cnt]) {
				flag = true;
				dfs(cnt + 1, l);
				break;
			}
			//y좌표가 같아도 선을 추가할 필요 x,위와 동
			if (l[i].second == arry[cnt]) {
				flag = true;
				dfs(cnt + 1, l);
				break;
			}
		}
		//현재 존재하는 선들과 수평/수직이 아닌경우
		if (!flag) {
			//선을 추가해준뒤, dfs실행
			l.push_back({ arrx[cnt],-1 });
			dfs(cnt + 1, l);
			l.pop_back();
            
			l.push_back({ -1,arry[cnt] });
			dfs(cnt + 1, l);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arrx[i] >> arry[i];
	}

	if (n <= 3) {
		cout << "1\n";
		return 0;
	}

	vector<pair<int, int>> l;
	dfs(0, l);

	cout << result << "\n";
}