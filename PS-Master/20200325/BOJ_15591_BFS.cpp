// <MooTube (Silver)> - BOJ_15591
// BFS버전

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e9;

int N,Q;
vector<vector<pii>> adj;
bool vi[5001]={false,};

int bfs(int st, int minU) {
	queue<pii> q;
	int cnt=0;
	q.push({st,INF});
	memset(vi,false,N+1);
	vi[st] = true;

	while(!q.empty()){
		int cur = q.front().first;
		int curMin = q.front().second;
		q.pop();

		for(auto val : adj[cur]){
			if(!vi[val.first]) {
				int a = curMin;
				if(val.second < curMin) a = val.second;
				q.push({val.first,a});
				if(a >= minU) cnt++;
				vi[val.first] = true;
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>Q;
	adj.resize(N+1);

	for(int i=1; i<N; i++){
		int p,q,r;
		cin>>p>>q>>r;
		adj[p].push_back({q,r});
		adj[q].push_back({p,r});
	}

	while(Q--){
		int k,v;
		cin>>k>>v; // v동영상에서 k보다 큰 유사도를 보유한 동영상 개수 추출
		cout<<bfs(v,k)<<'\n';
	}
}