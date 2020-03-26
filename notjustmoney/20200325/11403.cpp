#include <bits/stdc++.h>
using namespace std;
int G[100][100];
int main() {
	int N;	
	scanf("%d", &N);
	for(int i = 0; i < N; i++) 
	for(int j = 0; j < N; j++) 
		scanf("%d", &G[i][j]);			
	printf("\n");
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			bool p = false;
			if(!G[i][j]) {
				bool visited[N] = {false};
				queue<int> q;
				
				q.push(i);
				while(q.size()){
					int V = q.front();
					q.pop();
					if(p) break;
					for(int k = 0; k < N; k++) {
						if(G[V][k]) {
							if(!visited[k]) {
								if(k==j) p = true;
								visited[k] = true;
								q.push(k);
							}
						}
					}
				}
			} else p = true;
			if(p) printf("1 ");
			else  printf("0 ");
		}
		printf("\n");
	}

	return 0;	
}
