#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

vector<pair<int,int>> tree[100001];
int n,m;
int depth[100001];
int ancestor[100001][30];//ancestor[x][y]= x의 2의y제곱번째 조상
int maxEdge[100001][30];
int minEdge[100001][30];

int max_height=(int)floor(log2(100000));
void makeDepth(int now,int parent){
    depth[now]=depth[parent]+1;
    
    ancestor[now][0]=parent;
    
    //조상과, 그 조상까지의 최고 최대 간선 저장
    for(int i=1;i<=max_height;i++){
        int prev=ancestor[now][i-1];
        //조상 저장
        ancestor[now][i]=ancestor[prev][i-1];
        
        //내려가면서 최댓값,최솟값 업데이트 
        maxEdge[now][i]=max(maxEdge[now][i-1],maxEdge[prev][i-1]);
        minEdge[now][i]=min(minEdge[now][i-1],minEdge[prev][i-1]);
    }
    
    //dfs 돌면서 업데이트
    for(int i=0;i<tree[now].size();i++){
        int next=tree[now][i].first;
        int edgeCost=tree[now][i].second;
        
        //자신의 부모는 이미 돌았으므로 continue
        if(next==parent) continue;
            
        //now->next 의 2**0번째 조상까지의 최대 최솟값을 edgeCost로 일단 업데이트 후dfs실행
        maxEdge[next][0]=edgeCost;
        minEdge[next][0]=edgeCost;
        makeDepth(next,now);
    }
}

void lca(int a,int b){
    int minimum=1000000;
    int maximum=1;
    if(depth[a]!=depth[b]){
        if(depth[a]>depth[b]){
            int temp=a;
            a=b;
            b=temp;
        }
        for(int i=max_height;i>=0;i--){
            //한칸씩 올라가며 a와 b의 깊이를 맞춤, 그와 동시에 최대 최솟값 업데이트
            if(depth[a]<=depth[ancestor[b][i]]){
                minimum=min(minimum,minEdge[b][i]);
                maximum=max(maximum,maxEdge[b][i]);
                b=ancestor[b][i];
            }
        }
    }
    
    //높이만 맞췄는데 일치한다면, 출력 후 종료
    if(a==b){
        cout<<minimum<<" "<<maximum<<"\n";
        return;
    }
    if(a!=b){
        for(int i=max_height;i>=0;i--){
            if(ancestor[a][i]!=ancestor[b][i]){
                minimum=min(minimum,min(minEdge[a][i],minEdge[b][i]));
                maximum=max(maximum,max(maxEdge[b][i],maxEdge[a][i]));
                a=ancestor[a][i];
                b=ancestor[b][i];
            }
        }
    }
    minimum=min(minimum,min(minEdge[a][0],minEdge[b][0]));
    maximum=max(maximum,max(maxEdge[b][0],maxEdge[a][0]));
    cout<<minimum<<" "<<maximum<<"\n";
    return ;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }
    depth[0]=-1;
    
    makeDepth(1,0);
    
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        lca(a,b);
    }
    
}
