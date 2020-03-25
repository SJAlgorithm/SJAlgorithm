#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B, N, M;
	scanf("%d %d %d %d", &A, &B, &N, &M);
	
	bool visited[M] = {false};
	queue<int> q;
	queue<int> cq;
	q.push(N);
	cq.push(0);
	while(!q.empty()) {
		int pos = q.front();
		int count = cq.front();
		q.pop();
		cq.pop();
		if(pos==100001) {
			printf("%d\n", count);
			return 0;	
		}
		
		int current[8] = {
			pos+1,	
			pos-1,
			pos+A,
			pos-A,
			pos+B,
			pos-B,
			pos*A,
			pos*B
		};
		
		for(int i=0; i<8; i++){
			if(current[i]>=0 && current[i]<=100000)
				if(!visited[current[i]]){
					q.push(current[i]);
					visited[current[i]] = true;
					cq.push(count+1);
				}
		}
	}
}
