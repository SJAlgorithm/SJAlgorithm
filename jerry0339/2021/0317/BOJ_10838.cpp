// BOJ_10838 / 제한 3초
// LCA
// lca 쿼리당 O(N) 풀이 
// x,y 사이 노드 1000개 => N
// 쿼리개수 M: 3x(10^5)
// 전체 시간복잡도 : O(M*N)

#include<bits/stdc++.h>
#define xx first
#define yy second
#define MAX_N 100000
using namespace std;
typedef pair<int,int> pii;

int N,M, tmp=1;
int p[MAX_N+1]{};
int son[MAX_N+1]{};
int paint[MAX_N+1]{};

int lca(int x, int y){
    tmp++;
    while(1){
        if(x!=-1){
            if(son[x]==tmp) return x;
            son[x] = tmp;
            x = p[x];
        }
        
        if(y!=-1){
            if(son[y]==tmp) return y;
            son[y] = tmp;
            y = p[y];
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    p[0] = -1;
    
    int k,x,y,c;
    while(M--){
        cin>>k>>x>>y;
        if(k==1){ // paint
            cin>>c;
            int common = lca(x,y);
            while(x!=common){
                paint[x] = c;
                x = p[x];
            }
            while(y!=common){
                paint[y] = c;
                y = p[y];
            }
        } else if(k==2){ // move
            p[x] = y;
        } else if(k==3){ // count
            int common = lca(x,y);
            set<int> s;
            while(x!=common){
                s.insert(paint[x]);
                x = p[x];
            }
            while(y!=common){
                s.insert(paint[y]);
                y = p[y];
            }
            cout<<s.size()<<'\n';
        }
    }

}