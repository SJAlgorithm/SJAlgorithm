#include <bits/stdc++.h>
using namespace std;

int N;
bool e[1001][1001];

void rDFS(int V, bool* visited) {
	visited[V] = true;
	printf("%d ", V);
	for(int i=1; i<=N; i++) {
		if(e[V][i]) {
			if(!visited[i]) rDFS(i, visited);
		}
	}
	
}

void DFS(int V){
	bool visited[1001];
	rDFS(V, visited);
	printf("\n");
}

void BFS(int V){
	bool visited[N+1];
	vector<int> q;
	visited[V] = true;
	q.push_back(V);
	while(q.size() != 0) {
		V = q.front();
		q.erase(q.begin());
		printf("%d ", V);	
		for(int i=1; i<=N; i++) {
			if(e[V][i]){
				if(!visited[i]){
					visited[i] = true;
					q.push_back(i);	
				}
			}
		}
	}
}

int main() {
	int M, V;
	scanf("%d %d %d", &N, &M, &V);

	int n1, n2;
	for(int i=0; i<M; i++) {
		scanf("%d %d", &n1, &n2);
		e[n1][n2] = true;
		e[n2][n1] = true;
	}
	
	DFS(V);
	BFS(V);
	
	return 0;	
}
