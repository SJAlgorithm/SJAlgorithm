#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	int arr[101];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int tmp=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(arr[i]+arr[j]+arr[k]<=m){
					tmp=max(tmp,arr[i]+arr[j]+arr[k]);		
				}
			}
		}
	}
	cout<<tmp;
	return 0;
}