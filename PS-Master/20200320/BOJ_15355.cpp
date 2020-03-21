// <Programiranje> - BOJ_15355
// DP

#include<bits/stdc++.h>
using namespace std;

string str;
int q, cnt[50001][26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str>>q;
    for(int i=0; i<str.size(); i++){
		cnt[i+1][str[i]-'a'] = 1;
		for(int j=0; j<26; j++)
			cnt[i+1][j] += cnt[i][j];
	}

    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int i;
        for(i=0; i<26; i++){
            if(cnt[b][i] - cnt[a-1][i] != cnt[d][i] - cnt[c-1][i]) {
                cout<<"NE"<<'\n';
                break;
            }
        }
        if(i==26) cout<<"DA"<<'\n';
    }
}