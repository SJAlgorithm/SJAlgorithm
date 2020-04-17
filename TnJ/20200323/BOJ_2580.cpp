// <스도쿠> - BOJ_2580
// DFS를 이용한 백트래킹
// depth의 기준이 무엇인지 인식해야함

#include<bits/stdc++.h>
using namespace std;

int sdk[9][9]={0,};
bool squareCheck[9][10];
bool rowCheck[9][10];
bool columnCheck[9][10];
vector<pair<int,int>> v;
int cnt;

void initIndex(int i, int j) {
    int num = sdk[i][j];
    sdk[i][j] = 0;
    int k = (i-(i%3)) + j/3;
    squareCheck[k][num-1] = false;
    rowCheck[i][num-1] = false;
    columnCheck[j][num-1] = false;
}
void setIndex(int i, int j, int num) {
    sdk[i][j] = num;
    int k = (i-(i%3)) + j/3; // k : 3x3 정사각형 인덱스
    squareCheck[k][num-1] = true;
    rowCheck[i][num-1] = true;
    columnCheck[j][num-1] = true;
}

bool isPossible(int i, int j, int n) {
    int k=(i-(i%3)) + j/3;
    if(!squareCheck[k][n] && !rowCheck[i][n] && !columnCheck[j][n])
        return true;
    else return false;
}

void printSdk() {
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++)
            cout<<sdk[i][j]<<" ";
        cout<<'\n';
    }
}

void backTrack(int depth){ // depth의 기준 = 빈칸노드
    if(depth==cnt) {
        printSdk();
        exit(0);
    }
    int y = v[depth].first;
    int x = v[depth].second;
    for(int i=0; i<9; i++) { // depth에 뭐가 들어가야 하는지 탐색해야함 -> 빈칸(depth)에 들어가야 하는 수를 탐색.
        if(isPossible(y,x,i)){
            setIndex(y,x,i+1);
            backTrack(depth+1);
            initIndex(y,x);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            int num; cin>>num;
            if(!num) { // 0일경우 입력된 순서대로 벡터에 삽입
                v.push_back(make_pair(i,j));
                continue;
            }
            setIndex(i,j,num);
        }
    }
    cnt = v.size();
    backTrack(0);
}