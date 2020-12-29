#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,cnt=1; cin>>n;
    char buf; cin>>buf;
    n--;
    while(n--){
        char ch; cin>>ch;
        if(buf!=ch) {
            cnt++;
            buf = ch;
        }
    }
    cout<<cnt+1;
}