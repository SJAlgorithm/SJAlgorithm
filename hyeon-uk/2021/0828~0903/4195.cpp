#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
typedef struct node {
	int pa;
	int cnt;
}node;
int t, n;
node parent[200010];

int find(int a) {
	if (a == parent[a].pa) {
		return a;
	}
	else return find(parent[a].pa);
}


int union_parent(int a, int b) {
	a = find(a);
	b = find(b);
	//서로 다른 두 집합일때
	if (a > b) {
		parent[a].pa = b;//집합 union
		parent[b].cnt += parent[a].cnt;//부모노드에 cnt 추가
		return parent[b].cnt;
	}
	else if(a<b){
		parent[b].pa = a;//집합 union
		parent[a].cnt += parent[b].cnt;//부모노드에 cnt추가
		return parent[a].cnt;
	}
	//같은집합이면 바로 리턴
	else {
		return parent[a].cnt;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		map<string, int> p;
		int total = 0;
		cin >> n;
		for (int i = 0; i < 200010; i++) {
			parent[i] = { i,1 };
		}
		
		for (int i = 0; i < n; i++) {
			string n1, n2;
			cin >> n1 >> n2;
			if (!p[n1]) {
				p[n1] = ++total;
			}
			if (!p[n2]) {
				p[n2] = ++total;
			}
			int i1 = p[n1];
			int i2 = p[n2];
			cout << union_parent(i1, i2) << "\n";
		}
	}
	return 0;
}
