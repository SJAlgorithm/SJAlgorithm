#include <cstdio>
#include <queue>
#include<cstring>
using namespace std;

char str[20];
char arr[3][3];
bool check(){
	int oCount=0,xCount=0,spotCount=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(arr[i][j]=='.'){
				spotCount++;
			}else if(arr[i][j]=='O') oCount++;
			else xCount++;
		}
	}
	bool xwin=false;
	bool ywin= false;
	for(int i=0;i<3;i++){
		if(arr[i][0]=='O'&&arr[i][0]==arr[i][1] &&arr[i][1]==arr[i][2]) xwin=true;
		if(arr[0][i]=='O'&&arr[0][i]==arr[1][i] &&arr[1][i]==arr[2][i]) xwin=true;
	}
	if(arr[0][0]=='O'&&arr[0][0]==arr[1][1] &&arr[1][1]==arr[2][2]) xwin=true;
	if(arr[0][2]=='O'&&arr[0][2]==arr[1][1] &&arr[1][1]==arr[2][0]) xwin=true;
	
	for(int i=0;i<3;i++){
		if(arr[i][0]=='X'&&arr[i][0]==arr[i][1] &&arr[i][1]==arr[i][2]) ywin=true;
		if(arr[0][i]=='X'&&arr[0][i]==arr[1][i] &&arr[1][i]==arr[2][i]) ywin=true;
	}
	if(arr[0][0]=='X'&&arr[0][0]==arr[1][1] &&arr[1][1]==arr[2][2]) ywin=true;
	if(arr[0][2]=='X'&&arr[0][2]==arr[1][1] &&arr[1][1]==arr[2][0]) ywin=true;
	if(ywin && !xwin && xCount-oCount==1) return true;
	if(!ywin && xwin && xCount==oCount) return true;
	if(!ywin && !xwin &&xCount==5 && oCount==4) return true;
	
	return false;
}
int main() {
	while(1){
		scanf("%s",&str);
		if(!strcmp(str,"end")) break;
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				arr[j][k]=str[j*3+k];
			}
		}
		if(check()){
			printf("valid\n");
		}else{
			printf("invalid\n");
		}
	}
	return 0;
}