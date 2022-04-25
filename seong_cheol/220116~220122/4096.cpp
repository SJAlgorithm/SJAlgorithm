//
//  main.cpp
//  4096
//
//  Created by wi_seong on 2022/01/16.
//

#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

int N;
char str[10];

int func(int cur) {
    int tmp = 0;
    
    if (str[cur - 1] >= str[strlen(str) - cur]) {
        tmp = str[cur - 1] - str[strlen(str) - cur];

    }
    
    else {
        int times = 1;
        while(true) {
            if (str[strlen(str) - cur - times] == '9') {
                str[strlen(str) - cur - times] = '0';
                times++;
            } else {
                str[strlen(str) - cur - times] += 1;
                break;
            }
        }
        tmp = str[cur - 1] - str[strlen(str) - cur] + 10;
    }
    
    str[strlen(str) - cur] = str[cur - 1];
    if (cur == strlen(str)/2) {
        return tmp*(int)pow(10, cur-1);
    }
    return tmp*(int)pow(10, cur-1)+func(cur+1);
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> str;
    while(!(strlen(str)==1 && str[0]=='0')) {
        cout << func(1) << '\n';
        cin >> str;
    }
    
    return 0;
}
