#include <iostream>
#include<string>
using namespace std;
int main(void) {
	string des="87654321";
	string asc="12345678";
	string input="";
	for(int i=0;i<8;i++){
		string a;
		cin>>a;
		input+=a;
	}
	if(!des.compare(input)){
		cout<<"descending";
	}else if(!asc.compare(input)){
		cout<<"ascending";
	}else{
		cout<<"mixed";
	}
 
	return 0;
}
 