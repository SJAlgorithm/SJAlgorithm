#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

void swap(int arr[], int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int main() {
    int N;
    int shell[3] = { 0 };
    int arr[101][3];
    int answer[3] = { 0 };
    int cnt = 0, max = 0;
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        // 인덱스 0: a, 1: b, 2: g
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }
    
    for (int i = 0; i < 3; i++) {
        // 정답이 있는 곳을 1로 표시
        answer[i] = 1;
        
        for (int j = 0; j < N; j++) {
            // 단계별로 swap
            swap(answer, arr[j][0] - 1, arr[j][1] - 1);
            // answer[g]가 1이면 cnt++
            if (answer[arr[j][2] - 1] == 1) {
                cnt++;
            }
        }
        // i번째에 정답이 있을 때 카운트
        shell[i] = cnt;
        
        // 초기화
        cnt = 0;
        
        for (int j = 0; j < 3; j++) {
            answer[j] = 0;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        if (shell[i] > max) max = shell[i];
    }
    
    printf("%d\n", max);
    
    return 0;
}

