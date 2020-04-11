#include <bits/stdc++.h>
using namespace std;
bool adj[21][21];
int n, m;

bool isPossible() {
	vector<int> a;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(adj[i][j]) {
				a.push_back(j);	
			}
		}
		for(int j= 0; j < a.size(); j++) {
			for(int k = j; k < a.size(); k++) {
				if(j != k) {
					if(adj[a[j]][a[k]]) return false;	
				}
			}
		}
	}
	return true;
}

int main() {
	while(true) {
		scanf("%d %d", &n, &m);
		if(!(n|m)) return 0;
		for(int i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			adj[x][y] = adj[y][x] = true;
		}
		
		if(isPossible()) {
				
			
			printf("%d: ", cnt);
			
			continue;	
		}
		printf("Impossible\n");
	}
}
