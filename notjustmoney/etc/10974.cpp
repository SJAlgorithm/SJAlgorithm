#include <bits/stdc++.h>
using namespace std;

int N;
list<int> l;
bool visited[9];

void dfs(){
	if(l.size() == N) {
		for(auto iter = l.begin(); iter != l.end(); iter++) {
			printf("%d ", *iter);	
		}
		printf("\n");
		return;
	}
	for(int i = 1; i <= N; i++) {
		if(!visited[i]) {
			visited[i] = true;
			l.push_back(i);
			dfs();
			l.pop_back();
			visited[i] = false;
		}
	}

}

int main() {
	scanf("%d", &N);
	dfs();
	return 0;	
}
