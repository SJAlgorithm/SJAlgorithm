#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;

class Seg {
public:
	vector<int> arr;
	vector<ll> tree;
	Seg(int n) {
		arr.resize(n);
		int h = (int)ceil(log2(n));
		int tree_size = (1 << (h + 1));
		tree.resize(tree_size);
	}

	void input(int n) {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
	}

	int init(int node, int st, int end) {
		if (st == end) {
			return tree[node]=arr[st];
		}

		int middle = (st + end) / 2;
		int left = init(node * 2, st, middle);
		int right = init(node * 2 + 1, middle + 1, end);
		return tree[node] = (left<right?right:left);
	}

	int query(int node, int st, int end, int l, int r) {
		if (r < st || end < l) {
			return -1;
		}
		if (l <= st && end <= r) {
			return tree[node];
		}

		int middle = (st + end) / 2;
		int left = query(node * 2, st, middle, l, r);
		int right=query(node * 2 + 1, middle + 1, end, l, r);

		return (left < right ? right : left);
	}
};


int main() {
	int n, m;
	cin >> n >> m;
	m--;
	Seg seg(n);
	seg.input(n);
	seg.init(1,0,n-1);
	for (int i = m; i < n - m; i++) {
		cout << seg.query(1, 0, n - 1, i - m, i + m) << " ";
	}
	return 0;
}