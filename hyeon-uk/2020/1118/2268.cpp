#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;

ll tree[4 * 1000000];
ll arr[1000000];
int n,m;

ll init(int node, int st, int end) {
	if (st == end) {
		return tree[node] = arr[st];
	}

	int mid = (st + end) / 2;
	return init(node * 2, st, mid) + init(node * 2 + 1, mid + 1, end);
}

ll sum(int node, int st, int end, int left, int right) {
	if (left <= st && end <= right) {
		return tree[node];
	}
	if (right < st || end < left) {
		return 0;
	}

	int mid = (st + end) / 2;
	return sum(node * 2, st, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void modify(int node, int st, int end, int ind, long long dif) {
	if (ind < st || end < ind) return;
	tree[node] -= dif;
	
	if (st != end) {
		int mid = (st + end) / 2;
		modify(node * 2, st, mid, ind, dif);
		modify(node * 2 + 1, mid + 1, end, ind, dif);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;


	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			if (b > c) {
				int temp = b;
				b = c;
				c = temp;
			}
			cout << sum(1, 0, n - 1, b - 1, c - 1) << "\n";
		}
		else {
			long long diff = arr[b - 1] - c;
			arr[b - 1] = c;
			modify(1, 0, n - 1, b - 1, diff);
		}
	}
	return 0;
}