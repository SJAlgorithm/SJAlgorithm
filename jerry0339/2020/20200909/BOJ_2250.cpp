// <트리의 높이와 너비> - BOJ_2250
// 트리의 (h,w) 찾기, 중위순회

#include<bits/stdc++.h>
using namespace std;

int tree[10001][2]{}, rt, N;
bool vi[10001]{};
int ans[10001][2]{};

int C=1, mdpt=0;
void inO(int node, int dpt) {
    if(node == -1) return;
    inO(tree[node][0], dpt+1);
    ans[dpt][0] = min(ans[dpt][0], C);
    ans[dpt][1] = max(ans[dpt][1], C);
    C+=1;
    mdpt = max(mdpt, dpt);
    inO(tree[node][1], dpt+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int n,l,r;
    for(int i=1; i<=N; i++){
        cin>>n>>l>>r;
        tree[n][0] = l;
        tree[n][1] = r;
        if(l!=-1) vi[l] = true;
        if(r!=-1) vi[r] = true;
        ans[i][0] = 1e9;
    }
    for(int i=1; i<=N; i++) if(!vi[i]) {rt = i; break;}

    inO(rt,1);
    
    int max_=0, maxi=1;
    for(int k=1; k<=mdpt; k++){
        int t = ans[k][1]-ans[k][0]+1;
        if(max_ < t) {
            max_ = t;
            maxi = k;
        }
    }
    cout<<maxi<<' '<<max_;
}