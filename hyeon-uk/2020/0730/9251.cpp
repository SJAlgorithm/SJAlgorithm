#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

int dp[1001][1001] = { 0 };
string str1, str2;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> str1;
	cin >> str2;

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1.at(i - 1) == str2.at(j - 1)) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[str1.size()][str2.size()];
	
	return 0;
}