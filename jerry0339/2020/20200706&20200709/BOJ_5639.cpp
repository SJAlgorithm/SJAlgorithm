// <이진 검색 트리> - BOJ_5639
// upper_bound 분할정복을 이용한 Binary Search Tree

#include <bits/stdc++.h>
using namespace std;

int tree[10001];

void postOrder(int s, int e) {
	if (s >= e) return;
	int pivot = upper_bound(tree + s + 1, tree + e, tree[s]) -tree;
	
	postOrder(s+1, pivot);
	postOrder(pivot , e);
	cout<<tree[s]<<'\n'; // postOrder
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int idx = 1, tmp;
	while (cin >> tmp) {
		tree[idx++] = tmp;
	}

	postOrder(1, idx);
}