#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int MAX = 100001;
int n, m;
int par[MAX], lca[MAX], paint[MAX];

int getlca(int x, int y, int k) {
    if (x == y)return x;
    int cnt = 0;
    while (x&&cnt < 1000) {
        lca[x] = k;
        x = par[x];
        cnt++;
    }
    cnt = 0;
    while (y&&cnt < 1000) {
        if (lca[y] == k)
            return y;
        y = par[y];
    }
    return 0;
}

void solution(){

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int c, x, y, z;
        cin >> c >> x >> y;
        if (c == 1) {
            cin >> z;
            int anc = getlca(x, y, i);
            while (x != anc) {
                paint[x] = z;
                x = par[x];
            }
            while (y != anc) {
                paint[y] = z;
                y = par[y];
            }
        }
        else if (c == 2)
            par[x] = y;
        else {
            set<int> st;
            int anc = getlca(x, y, i);
            while (x != anc) {
                st.insert(paint[x]);
                x = par[x];
            }
            while (y != anc) {
                st.insert(paint[y]);
                y = par[y];
            }
            cout << st.size(); << '\n';
        }
    }


}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}