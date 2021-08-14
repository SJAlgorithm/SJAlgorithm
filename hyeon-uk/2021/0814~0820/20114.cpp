#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n, h, w;
char maze[1000][1000];
char result[100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> h >> w;
	memset(result, '?', sizeof(result));
	for (int i = 0; i <h; i++) {
		for (int j = 0; j < n*w; j++) {
			cin >> maze[i][j];

			int rindex = j / w;
			if (maze[i][j] != '?') {
				result[rindex] = maze[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << result[i];
	}


	return 0;
}