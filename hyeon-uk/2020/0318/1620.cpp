#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#pragma warning(disable:4996)
using namespace std;  
int main() { 
    map<string, int> pock_int_map;
    string int_pock_map[100000 + 1];
    int N, M; scanf("%d %d", &N, &M);
    // input
    for (int n_idx = 0; n_idx < N; n_idx++) {
        string pocketmon;    cin >> pocketmon;
        pock_int_map.insert({ pocketmon, n_idx + 1 });
        int_pock_map[n_idx + 1] = pocketmon;
    }
    for (int m_idx = 0; m_idx < M; m_idx++) {
        char order[21]; scanf("%s", order);
        // 숫자이면 
        if ('0' <= order[0] && order[0] <= '9') {
            int index = atoi(order);
            cout << int_pock_map[index] << "\n";
        }
        // 문자이면
        else 
            printf("%d\n", pock_int_map[string(order)]);
    }
    return 0;
}
