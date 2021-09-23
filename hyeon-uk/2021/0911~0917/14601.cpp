#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int maze[129][129] = { 0 };
int num = 1;
int k, x, y;

void print(int x1, int x2, int y1, int y2) {
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			if (maze[i][j] == 0) {
				maze[i][j] = num;
			}
		}
	}
	num++;
}

bool isClean(int x1, int x2, int y1, int y2) {
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			if (maze[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

void check(int x1,int x2, int y1,int y2) {
	if(x2-x1==1&&y2-y1==1){
		print(x1, x2, y1, y2);
		return;
	}
	else {
		int xmid = (x1 + x2) / 2;
		int ymid = (y1 + y2) / 2;

		if (isClean(x1, xmid, y1, ymid)) {
			maze[xmid][ymid] = num;
		}
		if (isClean(xmid+1,x2 , y1, ymid)) {
			maze[xmid+1][ymid] = num;
		}
		if (isClean(x1, xmid, ymid+1, y2)) {
			maze[xmid][ymid+1] = num;
		}
		if (isClean(xmid+1, x2, ymid + 1, y2)) {
			maze[xmid+1][ymid+1] = num;
		}
		num++;
		check(x1, xmid, y1, ymid);
		check(x1, xmid, ymid+1, y2);
		check(xmid+1, x2, y1, ymid);
		check(xmid+1, x2, ymid+1, y2);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> y >> x;
	k = pow(2, k);
	maze[x][y] = -1;
	check(1, k, 1, k);
	for (int i = k; i >=1; i--) {
		for (int j = 1; j<=k; j++) {
			cout << maze[i][j] << " ";
		}
		cout << "\n";
	}

}
