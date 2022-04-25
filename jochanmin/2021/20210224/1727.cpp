#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <string>
#include <stack>
#include <queue>

using namespace std;

const int inf = 987654321;
int n, m, t;
vector<int>man;
vector<int>W;
int dp[1001][1001];
int dfs(int Widx, int manidx)
{
	if (Widx == m)return 0;
	int&ret = dp[Widx][manidx];

	if (ret != -1)return ret;

	ret = inf;

	for (int i = manidx; i < n - (m - Widx) + 1; ++i)
	{
		ret = min(ret, dfs(Widx + 1, i + 1) + abs(W[Widx] - man[i]));
	}

	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));

	cin >> n >> m;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> t;

		man.push_back(t);
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> t;

		W.push_back(t);
	}

	if (n < m)
		swap(man, W), swap(n, m);

	sort(man.begin(), man.end());
	sort(W.begin(), W.end());

	cout << dfs(0, 0);
	return 0;
}