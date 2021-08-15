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

	ll init(int node, int st, int end) {
		if (st == end) {
			return tree[node]=arr[st];
		}

		int middle = (st + end) / 2;
		return tree[node] = init(node * 2, st, middle) + init(node * 2 + 1, middle + 1, end);
	}

	ll query(int node, int st, int end, int l, int r) {
		if (r < st || end < l) {
			return 0;
		}
		if (l <= st && end <= r) {
			return tree[node];
		}

		int middle = (st + end) / 2;
		return  query(node * 2, st, middle, l, r) + query(node * 2 + 1, middle + 1, end, l, r);
	}

	ll update_query(int node, int st, int end, int index,int val) {
		if (index < st || end < index) {
			return tree[node];
		}
		
		if (st == end) {
			return tree[node] = val;
		}
		int middle = (st + end) / 2;
		return tree[node] = update_query(node * 2, st, middle, index, val) + update_query(node * 2+1, middle + 1, end, index, val);
	}
};


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;

	Seg seg(n);
	seg.input(n);
	seg.init(1,0,n-1);
	for (int i = 0; i < q; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y) {
			int temp = x;
			x = y;
			y = temp;
		}
		cout << seg.query(1,0,n-1,x - 1, y - 1)<<"\n";
		seg.update_query(1,0,n-1, a - 1, b);
	}
	return 0;
}