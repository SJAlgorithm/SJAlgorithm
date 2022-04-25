#include <iostream>
#include <queue>
using namespace std;
int check[1000004];
int main() {
	int f,s,g,u,d;
	int cnt=-1;
	queue<int> q;
	scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);
	q.push(s);
	check[s]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now==g){
		 cnt=check[now]-1;
         break;
        }
		int step[]={now+u,now-d};
		for(int i=0;i<2;i++){
			if(step[i]>=1 && step[i]<=f &&!check[step[i]]){
				check[step[i]]=check[now]+1;
				q.push(step[i]);
			}
		}
	}
	if(cnt==-1)
		printf("use the stairs");
	else
	printf("%d",cnt);
	return 0;
}