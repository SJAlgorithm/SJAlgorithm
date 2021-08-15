#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 400001
using namespace std;
typedef long long ll;
ll maze[MAX],maze1[MAX];
vector<ll> arr;
int n, m;

void init(int node, int st, int en) {
	if (st == en) {
		maze[node] = arr[st];
		maze1[node] = arr[st];
		return;
	}

	int middle = (st + en) / 2;
	init(node * 2, st, middle);
	init(node * 2+1, middle+1, en);

	ll mi1 = maze[node * 2];
	ll mi2 = maze[node * 2 + 1];
	maze[node] = min(mi1, mi2);

	ll ma1 = maze1[node * 2];
	ll ma2 = maze1[node * 2 + 1];
	maze1[node] = max(ma1, ma2);
	return;
}

ll query(int node, int st, int en, int l, int r) {
	if (r < st || en < l) {
		return -1;
	}
	if (l <= st && en <= r) {
		return maze[node];
	}

	int middle = (st + en) / 2;
	ll m1 = query(node * 2, st, middle, l, r);
	ll m2 = query(node * 2 + 1, middle + 1, en, l, r);
	if (m1 == -1) {
		return m2;
	}
	else if(m2==-1){
		return m1;
	}
	else {
		return min(m1, m2);
	}
}

ll query1(int node, int st, int en, int l, int r) {
	if (r < st || en < l) {
		return -1;
	}
	if (l <= st && en <= r) {
		return maze1[node];
	}

	int middle = (st + en) / 2;
	ll m1 = query1(node * 2, st, middle, l, r);
	ll m2 = query1(node * 2 + 1, middle + 1, en, l, r);
	if (m1 == -1) {
		return m2;
	}
	else if (m2 == -1) {
		return m1;
	}
	else {
		return max(m1, m2);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << query(1, 0, n - 1, a - 1, b - 1) <<" "<<query1(1,0,n-1,a-1,b-1)<< "\n";
	}
	return 0;
}
