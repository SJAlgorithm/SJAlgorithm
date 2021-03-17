#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

bool cal(vector<int> &arr, int mid){
    vector<int> temp;

    int cnt = 1;
    int minV, maxV;

    minV = arr[0];
    maxV = arr[0];

    for (int i = 1; i < n; i++){
        
        if (arr[i] < minV) minV = arr[i];
        if (arr[i] > maxV) maxV = arr[i];

        if ((maxV - minV) > mid){
            cnt++;
            minV = arr[i];
            maxV = arr[i];
        }
    }
    return cnt <= m;
}
void solution(){

    cin >> n >> m;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    int right = *max_element(arr.begin(), arr.end());
    int left = 0;
    int res = right;

    while(left <= right){ // 적절한 값을 찾기 위해서 이분탐색으로 하나씩 돌려본다.
        int mid = (left + right) / 2;

        if (cal(arr, mid)){
            if (res > mid) res = mid; // 최솟값 업데이트해주기
            right = mid - 1;
        } else left = mid + 1;
    }


    cout << res << '\n';    

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}