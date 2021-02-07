// 크루스칼(Union-Find 이용)

#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

int N,M;
int parent[1000010]{};
vector<piii> line;

int find(int k) {
    if (k == parent[k]) return k;
    else return parent[k] = find(parent[k]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N>>M;
    int a,b,c;
    for(int i=0; i<=N; i++) parent[i] = i;
    for(int i=0; i<M; i++){
        cin>>a>>b>>c;
        line.push_back({c,{a,b}});
    }
    sort(line.begin(), line.end());

    int sum=0, last=0;
    for(auto v : line){
        int d = v.xx;
        int x = v.yy.xx;
        int y = v.yy.yy;
        if(find(x) == find(y)) continue;
        sum += d;
        last = d;
        merge(x,y);
    }

    cout<<sum-last;
}

