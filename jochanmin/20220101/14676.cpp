#include <cstdio>
#include<vector>
#include <algorithm>
using namespace std;

int degree[100001];
int spot[100001];

int main() {
	int n,m,k;
    scanf("%d %d %d",&n,&m,&k);

    vector<vector<int>> arr(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        arr[u].push_back(v);
        degree[v]++;
    }

    bool ret=false;
    for(int i=0;i<k;i++){
        int oper,num;
        scanf("%d %d",&oper,&num);
        if(ret) break;
        switch(oper){
            case 1:
            if(degree[num]==0){
                spot[num]++;
                if(spot[num]==1){
                    for(int j=0;j<arr[num].size();j++) degree[arr[num][j]]--;
                }
            }else{
                ret=true;
            }
            break;
            case 2:
            if(spot[num]==0){
                ret=true;
            }else{
                spot[num]--;
                if(spot[num]==0){
                    for(int j=0;j<arr[num].size();j++) degree[arr[num][j]]++;
                }
            }
            break;
        }
    }
    if(ret) printf("Lier!\n");
    else printf("King-God-Emperor\n");

	return 0;
}