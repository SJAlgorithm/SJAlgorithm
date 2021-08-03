#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;

int F, S, G, U, D;

void updown() {
	bool visited[1000001] = { 0 };
	queue<pair<int, int>> q;
	q.push({ S,0 });

	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (now == G) {
			cout << cnt << "\n";
			return;
		}

		if (now + U <= F && !visited[now + U]) {
			q.push({ now + U,cnt + 1 });
			visited[now + U] = true;
		}
		if (now - D >= 1 && !visited[now - D]) {
			q.push({ now - D,cnt + 1 });
			visited[now - D] = true;
		}
	}
	cout << "use the stairs\n";
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> F >> S >> G >> U >> D;
	updown();
	return 0;
}