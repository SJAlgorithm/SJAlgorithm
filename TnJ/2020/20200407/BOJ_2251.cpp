// <물통> - BOJ_2251
// BFS

#include<bits/stdc++.h>
using namespace std;

typedef struct water{
    int A;
    int B;
    int C;
}WT;
int A,B,C;
bool vi[204][204][204]={false,};
set<int> ans;

void bfs(){
    queue<WT> q;
    q.push({0,0,C});

    while(!q.empty()) {
        int a = q.front().A;
        int b = q.front().B;
        int c = q.front().C;
        q.pop();
        if(vi[a][b][c]) continue;
        vi[a][b][c] = true;
        if(a==0) ans.insert(c);

        // A -> B
		if(a + b > B) q.push({a+b-B,B,c});
		else q.push({0,a+b,c});		
		// A -> C
		if(a+c > C) q.push({a+c-C,b,C});
		else q.push({0, b,a+c});		
		// B -> C
		if(b + c > C) q.push({a, b+c-C,C});
		else q.push({a, 0, b+c});
		// C -> B
		if(b + c > B) q.push({a, B, b+c-B});
		else q.push({a, b+c, 0});
		// C -> A
		if(c + a > A) q.push({A, b, c+a-A});
		else q.push({a+c, b, 0});
		// B -> A
		if(b + a > A) q.push({A, a+b-A, c});
		else q.push({a+b, 0, c});
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B>>C;
    bfs();
    for(int val : ans) cout<<val<<' ';
    
}