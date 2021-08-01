#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int tree[4*100001];
int arr[100001];
int n,m;
int init(int node,int left,int right){
    if(left==right){
        return tree[node]=1;
    }
    
    int middle=(left+right)/2;
    
    return tree[node]=init(node*2,left,middle)+init(node*2+1,middle+1,right);
}

int query(int node,int left,int right,int order){
    if(left==right){
        return left;
    }
    
    int middle=(left+right)/2;
    
    if(order<=tree[2*node]){
        return query(node*2,left,middle,order);
    }
    else{
        return query(node*2+1,middle+1,right,order-tree[2*node]);
    }
    
}

int update(int node,int left,int right,int order){
    tree[node]--;
    if(left==right){
        return 0;
    }
    int middle=(left+right)/2;
    
    if(order<=middle){
        return update(node*2,left,middle,order);
    }
    else{
        return update(node*2+1,middle+1,right,order);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    init(1,1,n);
    
    int index=1;
    cout << "<";
    for (int i = 0; i < n; i++)
    {
        int size = n - i;
        index += m - 1;

        if (index % size == 0) index = size;
        else if (index > size) index %= size;
            
        int num = query(1, 1, n, index);
        update(1, 1, n, num);
          
        if (i == n - 1) cout << num;
        else cout << num << ", ";
    }
    cout << ">";
    return 0;
}

