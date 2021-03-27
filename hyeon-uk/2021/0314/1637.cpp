#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

typedef struct {
	long long a, b, c;
}node;
int n;
vector<node> v;

long long getcount(long long middle) {
	long long a, b, c, cnt = 0;
	for (long long i = 0; i < n; i++) {
		if (v[i].a <= middle) {
			a = v[i].a;
			b = v[i].b;
			c = v[i].c;
			b = min(b, middle);
			cnt += (b - a) / c + 1;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	long long left = INT32_MAX;
	long long right = 0;

	for (int i = 0; i < n; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
		left = min(left, a);
		right = max(right, b);
	}

	if (getcount(right) % 2 == 0) {
		cout << "NOTHING\n";
		return 0;
	}

	//해당 값 보다 작은 개수가 짝수면 홀수개의 숫자는 오른편에있음

	while (left <= right) {
		int middle = (left + right) / 2;
		if (getcount(middle) % 2 == 0) left = middle + 1;
		else right = middle - 1;
	}

	cout << left << " " << getcount(left) - getcount(left - 1);
}
