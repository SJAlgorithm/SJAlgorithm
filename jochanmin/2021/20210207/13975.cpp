#include <iostream>
#include<queue>
using namespace std;
typedef long long ll;
int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--){
		int k;
		ll sum=0;
		scanf("%d",&k);
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		ll num;
		for(int i=0;i<k;i++){
			scanf("%lld",&num);
			pq.push(num);
		}
		while(pq.size()!=1){
			ll one=pq.top();
			pq.pop();
			ll two=pq.top();
			pq.pop();
			sum+=(one+two);
			pq.push(one+two);
		}
		printf("%lld\n",sum);
	}
	return 0;
}