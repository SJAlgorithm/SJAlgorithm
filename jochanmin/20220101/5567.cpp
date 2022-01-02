#include<iostream>
using namespace std;
int map[501][501];
int check[501];
int n, m,a,b, cnt;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		if (map[1][i])
		{
			check[i] = 1;
			for (int j = 2; j <= n; j++)
			{
				if (map[i][j] == 1)
					check[j] = 1;
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (check[i] == 1)
			cnt++;
	}
	cout << cnt << endl;
}