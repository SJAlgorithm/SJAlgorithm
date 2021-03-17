#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<pair<int, int>> v; //{d,w}
bool visited[1000];//수행했는지에 대한 bool 배열

int main() {
	cin >> n;
	int maxD = -1;
	for (int i = 0; i < n; i++) {
		int d, w;
		cin >> d >> w;
		maxD = max(maxD, d);//제일 늦은 제출기한을 구함
		v.push_back({ d,w });
	}
	int sum = 0;
	
    //마지막날부터 1일차로 접근
	for (int i = maxD; i >= 1; i--) {
		int tempMax = -1;
		int tempInd = -1;
        
    	//입력받은 배열을 돌며 수행을 하지않았고, 마감날짜가 아직 안지난 과제들에대해
        //최댓값 갱신
		for (int j = n - 1; j >= 0; j--) {
        	
			if (!visited[j] && v[j].first >= i&&v[j].second>tempMax) {
				tempInd = j;
				tempMax = v[j].second;
			}
		}
        //조건에 해당하는 순서쌍이 있으면
        //더해준 뒤, 수행했다고 체크
		if (tempMax != -1) {
			sum += tempMax;
			visited[tempInd] = true;
		}
	}

	cout << sum << "\n";
}