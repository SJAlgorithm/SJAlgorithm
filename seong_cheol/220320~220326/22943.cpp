//
//  22943.cpp
//  main
//
//  Created by wi_seong on 2022/03/26.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long
int k, m;
vector<ll> primeNum;
bool chk1[100001];
bool chk2[100001];
int vis[10];

// 에라토스테네스의 체를 이용한 소수 만들기
void primeNumberSeive(int n) {
    vector<bool> isPrime(n + 1);
    for(int i = 2; i <= sqrt(n); i++)  {
        if(isPrime[i]) continue;
        for(int j = i * i; j <= n; j += i)
            isPrime[j] = true;
    }
    for(int i = 2; i <= n; i++)
        if(!isPrime[i]) primeNum.push_back(i);
}

bool check2(int val) {
    while(val % m ==0)
        val /= m;
    if(chk2[val] == 1)
        return true;
    return false;
}

int comb(int cur, int idx, int max, int val) {
    if(idx == max) {
        if(chk1[val] == 1 && check2(val))
            return 1;
        return 0;
    }
    int ret = 0;
    for(int i = cur; i <= 9; i++) {
        if(idx ==0 && i == 0)
            continue;
        if(vis[i] == 1)
            continue;
        vis[i] = 1;
        ret += comb(cur, idx + 1, max, val * 10 + i);
        vis[i] = 0;
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> m;
    primeNumberSeive(m);
    
    int primeSize = int(primeNum.size());
    for(int i = 0; i < primeSize; i++) {
        for(int j = i + 1; j < primeSize; j++) {
            if(primeNum[i] + primeNum[j] < 100000)
                chk1[primeNum[i] + primeNum[j]] = 1;
        }
        for(int j = i; j < primeSize; j++) {
            if(primeNum[i] + primeNum[j] < 100000)
                chk2[primeNum[i] * primeNum[j]] = 1;
        }
    }
    int ans = comb(0, 0, 1, 0);
    cout << ans;
    
    return 0;
}
