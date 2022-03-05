#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
using namespace std;
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	regex r(R"(^[A-F]?A+F+C+[A-F]?$)");
	int n;
	cin>>n;
	string str;
	for(int i=0;i<n;i++){
		cin>>str;
		if (regex_match(str, r)) // 정규식을 이용한 패턴 매칭
            cout << "Infected!" << endl;
        else cout << "Good" << endl;
	}
	return 0;
}