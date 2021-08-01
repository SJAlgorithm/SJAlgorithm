#include <iostream>
#include<algorithm>
#include<vector>
#define MAX 987654321
using namespace std;

vector<int> maze[100001];
int n;
int dp[100001][2];

int dfs(int now, int parent, int isPolice) {
	if (dp[now][isPolice] != MAX) {
		return dp[now][isPolice];
	}

	int police = 0;
	if (isPolice) police++;//자기자신노드에 경찰서가 있으면 개수+1

	for (int next : maze[now]) {
		if (next != parent) {
			if (!isPolice) {
				//부모에 경찰서가 없으면, 자식은 무조건 경찰서가 있어야함.
				police += dfs(next, now, 1);
			}
			else {
				//부모에 경찰서가 있으면, 자식은 있는거 or 없는것 중 더 작은쪽을 택하면됨
				police += min(dfs(next, now, 1), dfs(next, now, 0));
			}
		}
	}
	//해당 경우의 최솟값을 저장
	return dp[now][isPolice] = police;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		maze[a].push_back(b);
		maze[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i][1] = MAX;
	}

	cout << min(dfs(1, 0, 0), dfs(1, 0, 1));

	return 0;
}