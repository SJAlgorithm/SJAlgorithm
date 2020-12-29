// <요세푸스 문제 2> - BOJ_1168
// 세그 - 역추적(query)

#include<bits/stdc++.h>
#define MAX 100001
#define MAX_N 100001
using namespace std;

int arr[MAX_N]{};
int tree[MAX<<2]{};
int N,K;

int init(int n, int s, int e){
    if(s==e) return tree[n] = arr[s];
    int mid = (s+e)>>1;
    return tree[n] = init(n<<1, s, mid) + init(n<<1|1, mid+1, e);
}

void modify(int n, int s, int e, int idx, int diff){
    if(idx<s || idx>e) return;
    tree[n] += diff;
    if(s==e) return;
    int mid = (s+e)>>1;
    modify(n<<1, s, mid, idx, diff);
    modify(n<<1|1, mid+1, e, idx, diff);
}

int query(int n, int s, int e, int val){
    tree[n]--;
    if(s==e) return s;
    int mid = (s+e)>>1;
    if(val<=tree[n<<1]) return query(n<<1, s, mid, val);
    return query(n<<1|1, mid+1, e, val-tree[n<<1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i=1; i<=N; i++){
        arr[i] = 1;
    }
    init(1,1,N);
    cout<<'<';
    int val = K;
    while(tree[1]>1){
        cout<<query(1,1,N,val)<<", ";
        val = (val+(K-1))%tree[1];
        if(val==0) val=tree[1];
    }
    cout<<query(1,1,N,val)<<'>';

    return 0;
}