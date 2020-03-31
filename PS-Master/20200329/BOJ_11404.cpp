#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321; 

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
    
    for (k = 1; k <= n; k++){
		for (i = 1; i <= n; i++){
			for (j = 1; j <= n; j++){
				if (g[i][j] > g[i][k] + g[k][j])
					g[i][j] = g[i][k] + g[k][j];
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