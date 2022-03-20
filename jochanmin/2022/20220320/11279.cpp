#include <cstdio>
#include<queue>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	priority_queue<int> pq;
	
	for(int i=0;i<n;i++){
		int num;
		scanf("%d",&num);
		if(num==0){
			if(pq.empty()){
				printf("0\n");
			}else{
				printf("%d\n",pq.top());
				pq.pop();
			}
		}else{
			pq.push(num);
		}
	}
	return 0;
}