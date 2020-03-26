#include<bits/stdc++.h>
using namespace std;
int cnt_1,cnt_2,cnt_3;
int one[3]={1,0,0};
int two[3]={0,1,0};
int three[3]={0,0,1};
void swap(int * p,int a,int b){
	int tmp =p[a-1];
	*(p+a-1)=p[b-1];
	*(p+b-1)=tmp;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b,g;
		scanf("%d %d %d",&a,&b,&g);
		swap(one,a,b);swap(two,a,b);swap(three,a,b);
		if(one[g-1]==1)
		 cnt_1++;
		 if(two[g-1]==1)
		 cnt_2++;
		 if(three[g-1]==1)
		  cnt_3++;
		// 조약돌이 1번이라고 생각
	}
	printf("%d",max(cnt_1,max(cnt_2,cnt_3)));
	return 0;
}