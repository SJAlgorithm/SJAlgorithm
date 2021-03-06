#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int n,m;
vector<int> party[50];
vector<int> known;
int parent[51];

int getParent(int a){
    if(a==parent[a]){
        return a;
    }
    else{
        return getParent(parent[a]);
    }
}

void unionParent(int a,int b){
    a=getParent(a);
    b=getParent(b);
    
    if(a<b){
        parent[b]=a;
    }
    else{
        parent[a]=b;
    }
}

void init(){
    int k;
    for(int i=0;i<51;i++){
        parent[i]=i;
    }
    cin>>n>>m;
    cin>>k;
    //알고있는 사람 추가
    for(int i=0;i<k;i++){
        int data;
        cin>>data;
        known.push_back(data);
    }
    
    for(int i=0;i<m;i++){
        cin>>k;
        
        for(int j=0;j<k;j++){
            int data;
            cin>>data;
            party[i].push_back(data);
            //union으로 만날수있는 경우를 그래프로 엮음
            if(j!=0){
                unionParent(party[i][j],party[i][j-1]);
            }
        }
    }
}

//수행시간 O(n*m*k) k=알고있는사람의 수 
void solve(){
    int cnt=0;
    for(int i=0;i<m;i++){
        bool flag=true;
        //파티를 돌아다니면서 알고있는 사람과 연이 있는사람이 있는 파티인경우가 아니면 cnt++
        for(int j=0;j<party[i].size();j++){
            if(!flag) break;
            for(int k=0;k<known.size();k++){
                if(getParent(party[i][j])==getParent(known[k])){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    init();
    
    solve();
	return 0;
}