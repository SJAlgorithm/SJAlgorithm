#include <bits/stdc++.h>
using namespace std;

long long cut(int h, vector<int> tree){
	long long sum = 0;
	for(int i=0; i<tree.size(); i++){
		if(tree[i] > h) sum += (tree[i]-h);
	}
	return sum;
}

int main() {
	int N, M;
	int max = 0;
	scanf("%d %d", &N, &M);
	vector<int> tree(N);
	
	for(int i=0; i<N; i++){
		scanf("%d", &tree[i]);
		if(tree[i] > max) max = tree[i];
	}
	
	int start=1, end=max, mid;
	long long sum;
	
	while(start <= end) {
		mid = (start+end)/2;
		sum = cut(mid, tree);
		if(sum < M) {
			end = mid-1;	
		} else {
			start = mid+1;
		} 
	}
	printf("%d\n", end);
	return 0;
}
