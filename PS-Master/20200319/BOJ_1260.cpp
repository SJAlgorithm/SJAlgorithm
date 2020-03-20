//<DFS와 BFS>
// 인접리스트

#include <bits/stdc++.h>
using namespace std;

bool vi[1001];
vector<list<int>> v(1001);

void dfs(int st){
    cout<<st<<' ';
    vi[st] = true;
    for(int val : v[st]){
        if (!vi[val]) dfs(val);
    }
}

void bfs(int st){
    queue<int> q;
    memset(vi,false,sizeof(vi));
    q.push(st);
    vi[st] = true;
    while(!q.empty()){
        int n = q.front();
        cout<<n<<' ';
        q.pop();

        for(int val : v[n]){
            if(!vi[val]) {
                q.push(val);
                vi[val] = true;
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m, st;
	cin >> n >> m >> st; // n : 정점개수 , m : 간선개수 , v : 시작노드인덱스

	while (m--) {
		int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
	}

    for(int i=1; i<=n; i++)
        v[i].sort();

    dfs(st);
    cout<<"\n";
    bfs(st);
}