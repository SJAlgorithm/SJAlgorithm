#include <cstdio>
#include <string>
#include <stack>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	char s[51];
	for(int i=0;i<n;i++){
		bool flag=false;
		stack<char> si;
		scanf("%s",s);
		for(int j=0;s[j];j++){
			if(s[j]=='(')
				si.push('(');
			else{
				if(si.empty()){
					printf("NO\n");
					flag=true;
					break;
				}
				else
				 si.pop();
			}
			
		}
		if(flag)
		 continue;
		if(!si.empty())
		 printf("NO\n");
		else
		 printf("YES\n");
	}
	return 0;
}