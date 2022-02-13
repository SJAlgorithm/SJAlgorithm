#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
 
int n;
int dp[1002], road[1002];
vector<pair<int, int>> graph[1002];
 
int go(int idx)
{
    int i, weight;
 
    if (dp[idx] != -1)    return dp[idx];
    dp[idx] = 0;
 
    for (i = 0; i < graph[idx].size(); i++) {
        weight = go(graph[idx][i].first) + graph[idx][i].second;
 
        if (dp[idx] < weight) {
            dp[idx] = weight;
            road[idx] = graph[idx][i].first;
        }
    }
 
    return dp[idx];
}
 
void solve()
{
    int r = 1;
 
    memset(dp, -1, sizeof(dp));
    dp[n + 1] = 0;
 
    printf("%d\n", go(1));
 
    while (r <= n) {
        printf("%d ", r);
        r = road[r];
    }
    printf("1\n");
}
 
int main()
{
    int m;
    int i, from, to, weight;
 
    scanf("%d %d", &n, &m);
 
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &from, &to, &weight);
 
        if (to == 1)    to = n + 1;
        graph[from].push_back(make_pair(to, weight));
    }
 
    solve();
 
    return 0;
}