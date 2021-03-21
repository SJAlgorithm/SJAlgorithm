#include<iostream>
#include<algorithm>
#include<vector>
#define INF 987654321;
using namespace std;

bool checkFox[4001],checkWolf[4001][2];
int distFox[4001];
double distWolf[4001][2];
int n,m;
vector<pair<int,int>> maze[4001];

void dijkstarFox(){
    for(int i=2;i<=n;i++) distFox[i]=INF;
    distFox[1]=0;
    while(true){
        int minInd=0;
        int minValue=INF;        
        for(int i=1;i<=n;i++){
            if(!checkFox[i]&&minValue>distFox[i]){
                minValue=distFox[i];
                minInd=i;
            }
        }
        
        if(minInd==0) break;
        
        checkFox[minInd]=true;
        
        for(int i=0;i<maze[minInd].size();i++){
            int next=maze[minInd][i].first;
            int cost=maze[minInd][i].second;
            
            if(distFox[next]>cost+distFox[minInd]){
                distFox[next]=cost+distFox[minInd];
            }
        }
    }
}

void dijkstarWolf(){
    for(int i=1;i<=n;i++){
        distWolf[i][0]=distWolf[i][1]=(double)INF;
    }
    distWolf[1][0]=0.0;
    
    while(true){
        int minInd=0;
        double minValue=(double)INF; 
        int flag;
        for(int i=1;i<=n;i++){
            if(!checkWolf[i][0]&&minValue>distWolf[i][0]){
                minValue=distWolf[i][0];
                minInd=i;
                flag=1;
            }
            if(!checkWolf[i][1]&&minValue>distWolf[i][1]){
                minValue=distWolf[i][1];
                minInd=i;
                flag=0;
            }
        }
        
        if(minInd==0) break;
        
        checkWolf[minInd][!flag]=true;
        for(int i=0;i<maze[minInd].size();i++){
            int next=maze[minInd][i].first;
            double cost=(double)maze[minInd][i].second;
            
            if(flag){
                if(distWolf[next][1]>cost/2+distWolf[minInd][0]){
                    distWolf[next][1]=cost/2+distWolf[minInd][0];
                }
            }
            else{
                if(distWolf[next][0]>2*cost+distWolf[minInd][1]){
                    distWolf[next][0]=2*cost+distWolf[minInd][1];
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        
        maze[a].push_back({b,c});
        maze[b].push_back({a,c});
    }
    
    dijkstarFox();
    dijkstarWolf();
    
    // for(int i=1;i<=n;i++){
    //     cout<<distWolf[i][0]<<" "<<distWolf[i][1]<<"\n";
    // }
    
    int cnt=0;
    for(int i=2;i<=n;i++){
        if(distFox[i] < min(distWolf[i][0],distWolf[i][1])){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
}
