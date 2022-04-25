#include <cstdio>
#include <cstring>
#include<vector>
#include<algorithm>
using namespace std;

int k, n, f;
bool flag;
int visit[901];
int graph[901][901];
vector<int> back;
void dfs(int x) {
    visit[x] = true;
    back.push_back(x);

    if (k == back.size()) {
        for (auto &p : back) {
            printf("%d\n", p);

        }
        exit(0);
    }
    else {
        for (int i = x + 1; i <= n; i++) {
            if (!visit[i]) {
                bool chk = true;
                for (auto &p : back) {
                    if (!graph[i][p]) {
                        chk = false;
                        break;
                    }
                }
                if (chk) {
                    dfs(i);
                }
            }
        }
        back.pop_back();
    }
}
int main() {
    scanf("%d%d%d", &k, &n, &f);
    for (int i = 0; i < f; i++) {
        int a, b; scanf("%d%d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    for (int i = 1; i <= n; i++) {
        back.clear();
        memset(visit, 0, sizeof(visit));
        dfs(i);
    }
    printf("-1\n");
    return 0;
}