#include <bits/stdc++.h>
using namespace std;
int A, B, C;
bool v[204][204][204];
bool ans[204];
int main() {
	scanf("%d %d %d", &A, &B, &C);
	queue<pair<int, int> > q;
	q.push({0, 0});
	while(!q.empty()) {
		pair<int, int> n = q.front(); q.pop();
		int abc[3] = {n.first, n.second, C-(n.first+n.second)};
		if(v[abc[0]][abc[1]][abc[2]]) continue;
		v[abc[0]][abc[1]][abc[2]] = true;
		if(!abc[0]) ans[abc[2]] = true;
		
		if(abc[0]+abc[1] <= B) q.push({0, abc[0]+abc[1]});
		else q.push({abc[0]+abc[1]-B, B});
		if(abc[0]+abc[2] <= C) q.push({0, abc[1]});
		else q.push({abc[0]+abc[2]-C, abc[1]});
		if(abc[1]+abc[0] <= A) q.push({abc[1]+abc[0], 0});
		else q.push({A, abc[1]+abc[0]-A});
		if(abc[1]+abc[2] <= C) q.push({abc[0], 0});
		else q.push({abc[0], abc[1]+abc[2]-C});
		if(abc[2]+abc[0] <= A) q.push({abc[2]+abc[0], abc[1]});
		else q.push({A, abc[1]});
		if(abc[2]+abc[1] <= B) q.push({abc[0], abc[2]+abc[1]});
		else q.push({abc[0], B});
	}
	for(int i=0; i<=200; i++) {
		if(ans[i]) printf("%d ", i);	
	}
	printf("\n");
	return 0;	
}
