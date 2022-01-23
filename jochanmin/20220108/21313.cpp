#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		if(i%2==0){
			if(i==n-1)
				printf("3 ");
			else printf("1 ");
		}else printf("2 ");
		
	}
	return 0;
}