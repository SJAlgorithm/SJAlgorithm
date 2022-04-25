#include <string>
#include<algorithm>
#include<stack>
#include<iostream>
using namespace std;

string str;
stack<char> st;
int ans, piv=1;
bool vaild=true;
int main() {
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]=='('){
			piv*=2;
			st.push('(');
		}
		if(str[i]=='['){
			piv*=3;
			st.push('[');
		}
		if(str[i]==')'){
			if(!st.size() || st.top() != '('){
				vaild=false;
				break;
			}
			if(str[i-1]=='(') ans+=piv;
			piv/=2;
			st.pop();
		}
		if(str[i]==']'){
			if(!st.size()||st.top() !='['){vaild=false;break;}
			if(str[i-1]=='[') ans+=piv;
			piv/=3;
			st.pop();
		}
	}
	if(!vaild || st.size()) cout<<0;
	else cout<<ans;
	return 0;
}