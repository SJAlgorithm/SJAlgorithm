#include<iostream>
#include<vector>

using namespace std;

vector<int> maze[10001];
int depth[10001]={0};
int parent[10001]={0};

void make_depth(int now,int pa){
    depth[now]=depth[pa]+1;
    for(int next:maze[now]){
        if(next!=pa){
            make_depth(next,now);
        }
    }
}

int main() {
	
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<=n;i++){
            maze[i].clear();
            depth[i]=0;
            parent[i]=i;
        }
        for(int i=0;i<n-1;i++){
            int to,from;
            cin>>to>>from;
            maze[to].push_back(from);
            parent[from]=to;
        }
        int root=0;
        for(int i=1;i<=n;i++){
            if(parent[i]==i) root=i;
        }
        parent[root]=0;
        make_depth(root,0);
        int a,b;
        cin>>a>>b;
        
        if(depth[a]>depth[b]){
            int temp=a;
            a=b;
            b=temp;
        }
        while(depth[b]!=depth[a]){
            b=parent[b];
        }
        if(a==b){
            cout<<a<<"\n";
        }
        else{
        
            while(parent[a]!=parent[b]){
                a=parent[a];
                b=parent[b];
            }

            cout<<parent[a]<<"\n";
        }
    }
    
	return 0;
}