// <낚시왕> - BOJ_17143
// 빡구현 문제

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define aa first
#define bb second
#define all(v) (v).begin(), (v).end()
const int MAX = 1e9;//-> 1000000000

struct shk {
    int i, j;
    int s;
    int d;
    int z;
};
shk setz{};
shk m[101][101]{};
vector<shk> st;
int R, C, S;

// st<-상어정보

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C >> S;
    int r, c, s, d, z;
    while (S--) {
        shk t;
        cin >> t.i >> t.j >> t.s >> t.d >> t.z;
        int a = t.i;
        int b = t.j;
        if(t.d==1) t.i = R + (R - t.i);
        if(t.d==4) t.j = C + (C - t.j);
        m[a][b] = t;
    }

    int ans = 0;
    for (int k = 1; k <= C; k++) {
        
        for(int i=1; i<=R; i++){
            if(m[i][k].d) {
                ans+=m[i][k].z;
                m[i][k] = setz;
                break;
            }
        }

        st.clear();
        for (int i=1; i<=R; i++) {
            for(int j=1; j<=C; j++){
                if(!m[i][j].d) continue;
                if (m[i][j].d < 3) {
                    int t = (m[i][j].i + m[i][j].s) % ((R - 1) * 2);
                    if (!t) t = (R - 1) * 2;
                    m[i][j].i = t;
                }
                else {
                    int t = (m[i][j].j + m[i][j].s) % ((C - 1) * 2);
                    if (!t) t = (C - 1) * 2;
                    m[i][j].j = t;
                }
                st.push_back(m[i][j]);
            }
        }
        memset(m,0,sizeof(m));
        
        for(auto val : st){
            int a = val.i <= R ? val.i : R - val.i%R;
            int b = val.j <= C ? val.j : C - val.j%C;
            if(!m[a][b].d) m[a][b] = val;
            else {
                if(m[a][b].z < val.z) m[a][b] = val;
            }
        }
    }
    cout << ans;
}

// 