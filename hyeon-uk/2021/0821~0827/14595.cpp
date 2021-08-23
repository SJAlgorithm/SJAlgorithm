#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int,int> pii;

int n,m;
vector<pii> v;

int main() {
    cin>>n>>m;
    /*
    만약 빅 종빈이 행동하지 않으면
    모든 방은 살아있으므로
    방 개수 출력
    */
    if(m==0){
        cout<<n<<"\n";
        return 0;
    }
    
    //빅 종빈의 행동 입력
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    //시작방 기준 오름차순 정렬
    sort(v.begin(),v.end());
    
    
    //처음 행동을 시작하는 방과 끝방 선언
    int left=v[0].first;
    int right=v[0].second;
    int ret;
    
    /*
    만약 처음시작하는 방이 1번방이면, 초기 방의 개수는 1개가되고,
    아니라면, 1~ (left-1) 번방들은 모두 단독으로 살아있고,
    left~right로 합쳐진 방이 1개 있으므로, 초기 방의 개수는 left개가 된다.
    */
    if(left==1){
        ret=1;
    }
    else{
        ret=left;
    }
        

    for(int i=1;i<m;i++){
        //다음행동이 left와 right사이에 있으면 합쳐지므로 right갱신
        if(v[i].first<=right){
            right=max(right,v[i].second);
        }
        //아니면 방의 개수, left,right 갱신
        else{
            ret+=(v[i].first-right);//갱신할때 사이에 단독으로 살아있는방들 고려
            left=v[i].first;
            right=v[i].second;
        }
    }
    
    //행동이 끝났을때 마지막방이 아니라면, right+1~N번방의 개수를 추가
    if(right!=n){
        ret+=(n-right);
    }
    cout<<ret;
    
	return 0;
}