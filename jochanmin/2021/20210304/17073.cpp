#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n,w,u,v;
int arr[500001];
double cnt;
int main() {
	scanf("%d %d",&n,&w);
	for(int i=0;i<n-1;i++){
		scanf("%d %d",&u,&v);
		arr[u]++;
		arr[v]++;
	}
	for (int i=2; i<=n; i++){
        if (arr[i] == 1) cnt++;
	}
    printf("%.10f", (double)w / cnt);
    
	return 0;
}