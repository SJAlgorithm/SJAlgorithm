// <플로이드> - BOJ_11404
// 플로이드 와샬

#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321; 
// 무한값 : INF항상 크게 잡기.... (가중치를 더했을경우 값이 INF넘어 가지 않게)

int n,m;
int g[110][110]={0,};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i,j,k;
    cin>>n>>m;

    // init
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            g[i][j] = i==j ? 0 : INF;
        }
    }


    for(int i=0; i<m; i++) {
        int a,b,c; cin>>a>>b>>c;
        if(g[a][b] > c) g[a][b] = c;
    }
    
    for (i = 1; i <= n; i++){ // 탐색하는 노드를 for문 최상위에 놓아야함. (k >> 'i' >> j)
		for (j = 1; j <= n; j++){
			for (k = 1; k <= n; k++){
				if (g[k][j] > g[k][i] + g[i][j])
					g[k][j] = g[k][i] + g[i][j];
			}
		}
	}

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(g[i][j]==INF) {
                cout<<"0 ";
                continue;
            }
            cout<<g[i][j]<<' ';
        }
        cout<<'\n';
    }

}