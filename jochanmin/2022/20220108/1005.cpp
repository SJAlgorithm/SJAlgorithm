#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,k;
        int d[1001],dp[1001],ingree[1001];
        int target;
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++){
            scanf("%d",&d[i]);
            dp[i]=d[i];
            ingree[i]=0;
        }
        vector<int> arr[1001];
        for(int i=0;i<k;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            arr[u-1].push_back(v-1);
            ingree[v-1]++;
        }
        scanf("%d",&target);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(ingree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int next:arr[cur]){
                dp[next]=max(dp[next],dp[cur]+d[next]);
                if(--ingree[next]==0) q.push(next);
            }
        }
        printf("%d\n",dp[target-1]);
    }
}