#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int n;
int visited[26] = { 0 };
string str;
string answer;

void dfs(int index,int size) {
	if (index == size) {
		cout << answer << "\n";
		return;
	}
	for (int i = 0; i < 26; i++) {
		if (visited[i]) {
			visited[i]--;
			answer.push_back('a' + i);
			dfs(index + 1, size);
			answer.pop_back();
			visited[i]++;
		}
	}
}

void solve() {
	for (int i = 0; i < 26; i++) {
		visited[i] = 0;
	}
	answer = "";
	int size = str.size();
	for (int i = 0; i < size; i++) {
		visited[str[i] - 'a']++;
	}
	dfs(0,size);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		solve();
	}
}
