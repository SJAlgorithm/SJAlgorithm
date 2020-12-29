// <트리> - BOJ_4256
// 재귀, 트리
// PreOrder, InOrder결과를 이용하여 트리의 PostOrder출력하기

#include<bits/stdc++.h>
using namespace std;

int N,T;
int tree[1001][2]; // [0]: left, [1]: right
int po[1001]; // preOrder
int io[1001]; // intOrder

int makeTree(int l, int r, int k){
    if(l+1==r) return io[l];
    for(int i=l; i<r; i++) {
        if(po[k] == io[i]) {
            if(i!=l) tree[po[k]][0] = makeTree(l,i,k+1);
            if(i+1!=r) tree[po[k]][1] = makeTree(i+1,r,k+(i+1-l)); // 5,8,5
            break;
        }
    }
    return po[k];
}

void postorder(int node) {
    if (node == -1) return;
    postorder(tree[node][0]);
    postorder(tree[node][1]);
    cout<<node<<' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        memset(tree,-1,sizeof(tree));
        cin >> N;
        for(int i=0; i<N; i++) cin>>po[i];
        for(int i=0; i<N; i++) cin>>io[i];
        
        int root = makeTree(0,N,0);

        postorder(root); cout << "\n";
    }
    
}