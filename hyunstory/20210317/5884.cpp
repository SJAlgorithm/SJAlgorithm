#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<int, int> xm;
map<int, int> ym;

vector<pair<int, int> > a;

typedef struct ii{
    int cnt;
    bool isX;
    int cor;

    ii(int cnt, int isX, int cor): cnt(cnt), isX(isX), cor(cor){};
}ii;

bool operator <(ii u, ii v){ // > 로 바꾸면 인식을 못한다. 값을 받아와서 로직을 바꾼다.

    if (u.cnt == v.cnt) return u.cor < v.cor; // 사실은 0 인덱스 쪽에 가장 큰 값이 
    return u.cnt < v.cnt; // 0인덱스 쪽에 가장 큰 값이
}
int n;


void solution(){

    cin >> n;

    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});

        if (xm.find(x) != xm.end()){
            xm[x]++;
        } else xm[x] = 1;
        if (ym.find(y) != ym.end()){
            ym[y]++;
        } else ym[y] = 1;
    }


    priority_queue<ii> pq;

    for (const auto &a : xm){
        int x = a.first;
        int cnt = a.second;
        pq.push(ii(cnt, true, x));
    }

    for (const auto &a : ym){
        int y = a.first;
        int cnt = a.second;
        pq.push(ii(cnt, false, y));
    }


    vector<ii> selected;

    for (int i = 0; i < 3; i++){
        int cnt = pq.top().cnt;
        bool isX = pq.top().isX;
        int cor = pq.top().cor;
        selected.push_back(ii(cnt, isX, cor));

        pq.pop();
    }

    for (int i = 0; i < n; i++){
        int x = a[i].first;
        int y = a[i].second;

        bool isIn = false;

        for (int j = 0; j < 3; j++){
            int cnt = selected[j].cnt;
            int isX = selected[j].isX;
            int cor = selected[j].cor;

            if (isX){ // X 좌표일 때
                if (x == cor) isIn = true;
            } else { // Y 좌표일 때
                if (y == cor) isIn = true;
            }
        }

        if(!isIn){ // 최상위 3개에 존재하지 않은 좌표가 있다면 커버할 수 없는 좌표임
            cout << 0 << '\n';
            exit(0);
        }

    }

    cout << 1 << '\n';



}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution();

    return 0;
}