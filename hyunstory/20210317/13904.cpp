#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
const int MAX = 1001;
int dayScore[MAX];

vector< pair<int, int> > vec;

bool comp(pair<int,int> p1, pair<int,int> p2){
    if (p1.second == p2.second) return p1.first < p2.first; // 스코어가 같다면 일자가 좀 더 작은 순으로 찾기.(과제가 금방 없어지기 때문)
    else return p1.second > p2.second;  // 스코어가 더 큰 순서대로 정렬

}
void solution(){
    cin >> n;

    for (int i = 0; i < n; i++){
        int d, s;
        cin >> d >> s;
        vec.push_back({d, s});
    }

    sort(vec.begin(), vec.end(), comp);

    for (int i = 0; i < n; i++){
        int day = vec[i].first - 1;
        int score = vec[i].second;

        while(dayScore[day]) day--; // 비어있는 날짜 찾아보기

        if (day >= 0) dayScore[day] = score; // 만약 0이상의 비어있느 날짜를 찾았다면 해당 과제를 할 수 있기 때문에 스코어 입력
        
    }

    int result = 0;

    for (int i = 0; i < MAX; i++){
        result += dayScore[i]; // 각 각의 날 동안 할 수 있는 작업 모두 더하기
    }

    cout << result << '\n';

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}
