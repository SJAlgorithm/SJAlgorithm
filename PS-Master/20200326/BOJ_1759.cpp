// <암호만들기> BOJ_1759
// 백트래킹 dfs

#include<bits/stdc++.h>
using namespace std;

int L,C,flag =0,flag2 =0;
char ch[20]={0,};
char str[20]={0,};

bool check(char ch){
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
    else return false;
}

void dfs(int depth, int cur) {
    if(depth == L && flag!=0 && flag2 >1) {
        cout<<str<<'\n';
        return;
    }

    for(int i=cur; i<C; i++){
        if(1){
            if(check(ch[i])) flag++;
            else flag2++;
            str[depth] = ch[i];
            dfs(depth+1,i+1);
            if(check(ch[i])) flag--;
            else flag2--;
            str[depth] = 0;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>L>>C;
    for(int i=0; i<C; i++) cin>>ch[i];
    sort(ch,ch+C);
    dfs(0,0);
}