// <크로스 워드> - BOJ_1706
// 문자열, 정렬
#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()

int R,C;
char m[22][22]{};
vector<string> v;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>R>>C;
    string str;

    for(int i=1; i<=R; i++){
        cin>>str;
        for(int j=1; j<=C; j++){
            m[i][j]=str[j-1];
        }
    }
    
    for(int i=1; i<=R; i++){
        string t="";
        for(int j=1; j<=C; j++){
            if(m[i][j]=='#'){
                if(t.size()>1){
                    v.push_back(t);
                }
                t="";
            }else{
                t+=m[i][j];
            }
        }
        if(t.size()>1){
            v.push_back(t);
        }
    }
    for(int j=1; j<=C; j++){
        string t="";
        for(int i=1; i<=R; i++){
            if(m[i][j]=='#'){
                if(t.size()>1){
                    v.push_back(t);
                }
                t="";
            }else{
                t+=m[i][j];
            }
        }
        if(t.size()>1){
            v.push_back(t);
        }
    }

    sort(all(v));
    cout<<v[0];
}