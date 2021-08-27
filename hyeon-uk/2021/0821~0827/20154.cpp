#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

int cnt[26] = { 3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1 };
int score=0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		score += cnt[c - 'A'];
	}
	score %= 10;
	if (score % 2 == 0) {
		cout << "You're the winner?";
	}
	else {
		cout << "I'm a winner!";
	}

	return 0;
}