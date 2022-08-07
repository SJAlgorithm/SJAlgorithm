#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;

int n,k;
int m[1001]{};
int parent[1001]{};

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    while(1) {
        cin>>n>>k;
        if(n==0 && k==0) break;
    
        int target;
        for (int i = 0; i < n; i++) {
            cin>>m[i];
            if (m[i] == k) target = i;
        }
        if(target == 0) {cout<<0<<'\n'; continue;}

        int idx = -1;
        parent[0] = -1;
        for (int i=1; i<n; i++) {
            if (m[i] != m[i-1]+1) idx++;
            parent[i] = idx;
        }

        int ans = 0;
        for (int i = 1; i < n; i++){
            int x = parent[i];
            int y = parent[target];
            if (parent[x] == parent[y] && x != y) ans++;
        }
        
        cout<<ans<<'\n';
    }
    
}