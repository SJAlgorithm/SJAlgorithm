#include <algorithm>
#include<iostream>
#include<vector>
#define INF 987654321
using namespace std;

long long maze[101][101]={0};
int N,M,K,T;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin>>T;
    while(T--){
        vector<int> friends;
        cin>>N>>M;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                maze[i][j]=INF;
            }
        }
        for(int i=0;i<M;i++){
            int a,b,c;
            cin>>a>>b>>c;
            maze[a][b]=c;
            maze[b][a]=c;
        }
        for(int k=1;k<=N;k++){
            for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++){
                    if(i==j||j==k||i==k) continue;
                    maze[i][j]=min(maze[i][j],maze[i][k]+maze[k][j]);
                }
            }
        }
        cin>>K;
        for(int i=0;i<K;i++){
            int data;
            cin>>data;
            friends.push_back(data);
        }
        long long min_dist=INF;
        int room=-1;
        for(int i=1;i<=N;i++){
            long long sum=0;
            for(int j=0;j<K;j++){
                if(maze[i][friends[j]]!=INF){
                    sum+=maze[i][friends[j]];   
                }
            }
            if(min_dist>sum){
                min_dist=sum;
                room=i;
            }
        }
        cout<<room<<"\n";
    }
    
   
}