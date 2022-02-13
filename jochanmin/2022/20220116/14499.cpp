#include <iostream>
using namespace std;
int n,m;
int arr[20][20]={0};
int dice[6]={0};
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};


int main(){
    int x,y,k;
    int t,tmp_dice[6];
    cin>> n>>m>>y>>x>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>> arr[i][j];
        }
    }
    
    for(int i=0; i<k; i++){
        cin>> t;
        t-=1;
        if(y+dy[t]<0 ||y+dy[t]>=n || x+dx[t]<0||x+dx[t]>=m) {continue;}
        
        for(int j=0; j<6; j++){tmp_dice[j] = dice[j];}
        y = y + dy[t];
        x = x + dx[t];
        if(t==0){
            dice[2] = tmp_dice[0];
            dice[0] = tmp_dice[3];
            dice[3] = tmp_dice[5];
            dice[5] = tmp_dice[2];
        }else if(t==1){
            dice[0] = tmp_dice[2];
            dice[3] = tmp_dice[0];
            dice[5] = tmp_dice[3];
            dice[2] = tmp_dice[5];
        }else if(t==2){
            dice[0] = tmp_dice[1];
            dice[4] = tmp_dice[0];
            dice[5] = tmp_dice[4];
            dice[1] = tmp_dice[5];
        }else{
            dice[1] = tmp_dice[0];
            dice[0] = tmp_dice[4];
            dice[4] = tmp_dice[5];
            dice[5] = tmp_dice[1];
        }
        if(arr[y][x] ==0){
            arr[y][x] = dice[5];
        }else{
            dice[5] = arr[y][x];
            arr[y][x] = 0;
        }
        cout << dice[0]<<"\n";
    }
    
    return 0;
}