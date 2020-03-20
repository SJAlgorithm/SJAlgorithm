// <영화감독 숌>

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,cnt=0; cin>>n;

    for(int i=666; ;i++){
        string str = to_string(i);
        if(str.find("666")!= -1) cnt++;
        if(cnt == n) {
            cout<<str;
            return 0;
        }
    }

}